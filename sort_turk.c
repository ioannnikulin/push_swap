/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 15:10:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

t_turk_rots	find_cheapest(t_turk_params *p, int toa);
int	three(t_dlist **a);
t_dlist	*mark_lis(t_dlist *a, int asz);

static int	send_cheapest(t_turk_params *p, t_turk_rots rs, int toa)
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

static int	pour_into_a(t_turk_params *p)
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

static int	send_one_to_b(t_turk_params *p)
{
	int	fwd;
	int	bwd;
	t_dlist	*np;
	int	res;

	fwd = 0;
	bwd = 0;
	np = *(p->a);
	while ((np->flags & LEAVE_IN_A) > 0)
	{
		np = np->next;
		fwd ++;
	}
	np = *(p->a);
	while ((np->flags & LEAVE_IN_A) > 0)
	{
		np = np->prev;
		bwd ++;
	}
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

static int	debut(t_turk_params *p)
{
	int	turns;

	int srt = sorted(*(p->a));
	if (p->asz < 2 || sorted(*(p->a)) == p->asz || srt == p->asz)
		return (0);
	if (p->asz == 2)
	{
		op_sa(p->a);
		return (1);
	}
	if (p->asz == 3)
		return (three(p->a) + pour_into_a(p));
	p->lis_start = mark_lis(*(p->a), p->asz);
	turns = send_one_to_b(p);
	if (p->lis_start->lisl == p->asz)
		return (turns + pour_into_a(p));
	if (p->asz == 3)
		return (three(p->a) + pour_into_a(p));
	turns += send_one_to_b(p);
	if (p->lis_start->lisl == p->asz)
		return (turns + pour_into_a(p));
	if (p->asz == 3)
		return (three(p->a) + pour_into_a(p));
	return (-turns);
}

int	sort_turk(t_dlist **a, t_dlist **b)
{
	int				turns;
	t_turk_params	params;
	int				sent;

	params.asz = ft_dlist_size(*a);
	params.bsz = 0;
	params.a = a;
	params.b = b;
	turns = debut(&params);
	if ((CUR_DEBUG & STAGE_RESULT_PRINT) > 0)
		print(*a, *b, iprinter);
	if (turns >= 0)
		return (turns);
	turns = -turns;
	sent = 2;
	while (params.asz > params.lis_start->lisl)
	{
		turns += send_cheapest(&params, find_cheapest(&params, 0), 0);
		sent ++;
	}
	turns += pour_into_a(&params);
	if ((CUR_DEBUG & STAGE_RESULT_PRINT) > 0)
		print(*a, *b, iprinter);
	return (turns + 2);
}
