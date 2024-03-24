/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_procs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/24 16:06:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

t_turk_rots	find_cheapest(t_turk_params *p, int toa);

int	send_cheapest(t_turk_params *p, t_turk_rots rs, int toa)
{
	while (rs.ras --)
		op_ra(p->a);
	while (rs.rbs --)
		op_rb(p->b);
	while (rs.rrs --)
		op_rr(p->a, p->b);
	while (rs.rras --)
		op_rra(p->a);
	while (rs.rrbs --)
		op_rrb(p->b);
	while (rs.rrrs --)
		op_rrr(p->a, p->b);
	if (toa)
	{
		op_pa(p->a, p->b);
		p->asz ++;
		p->bsz --;
		return (rs.total);
	}
	op_pb(p->a, p->b);
	p->asz --;
	p->bsz ++;
	if ((CUR_DEBUG & STAGE_RESULT_PRINT) > 0)
		print(*(p->a), *(p->b), iprinter);
	return (rs.total);
}

int	pour_into_a(t_turk_params *p)
{
	int		turns;
	t_dlist	*rt;
	int		tail;

	turns = 0;
	while (p->bsz > 0)
		turns += send_cheapest(p, find_cheapest(p, 1), 1);
	rt = *(p->a);
	tail = sorted(*(p->a));
	if (tail == p->asz)
		return (turns);
	if (tail <= p->asz / 2)
	{
		while (tail-- > 0 && ++ turns)
			op_ra(p->a);
		return (turns);
	}
	while (tail ++ < p->asz && ++ turns)
		op_rra(p->a);
	return (turns);
}

static int	closest_nonblocked(t_turk_params *p, int fwd)
{
	int		res;
	t_dlist	*np;

	np = *(p->a);
	res = 0;
	while ((np->flags & LEAVE_IN_A) > 0)
	{
		if (fwd)
			np = np->next;
		else
			np = np->prev;
		res ++;
	}
	return (res);
}

int	send_one_to_b(t_turk_params *p)
{
	int		fwd;
	int		bwd;
	int		res;

	fwd = closest_nonblocked(p, 1);
	bwd = closest_nonblocked(p, 0);
	p->asz --;
	p->bsz ++;
	if (fwd < bwd)
	{
		res = fwd + 1;
		while (fwd --)
			op_ra(p->a);
		op_pb(p->a, p->b);
		return (res);
	}
	res = bwd + 1;
	while (bwd --)
		op_rra(p->a);
	op_pb(p->a, p->b);
	return (res);
}
