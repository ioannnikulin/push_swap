/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/02 18:51:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

t_turk_rots	find_cheapest(t_turk_params *p, int toa);
int	three(t_dlist **a);

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
	#if (CUR_DEBUG & STAGE_RESULT_PRINT) > 0
	print(*(p->a), *(p->b), iprinter);
	#endif
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

static int	debut(t_turk_params *p)
{
	if (p->asz < 2 || sorted(*(p->a)) == p->asz)
		return (0);
	if (p->asz == 2)
	{
		op_sa(p->a);
		return (1);
	}
	if (p->asz == 3)
		return (three(p->a) + pour_into_a(p));
	op_pb(p->a, p->b);
	p->bsz ++;
	p->asz --;
	if (sorted(*(p->a)) == p->asz)
		return (1 + pour_into_a(p));
	op_pb(p->a, p->b);
	p->bsz ++;
	p->asz --;
	if (sorted(*(p->a)) == p->asz)
		return (2 + pour_into_a(p));
	return (-1);
}

int	sort_turk(t_dlist **a, t_dlist **b)
{
	int				turns;
	t_turk_params	params;

	params.asz = ft_dlist_size(*a);
	params.bsz = 0;
	params.a = a;
	params.b = b;
	turns = debut(&params);
	#if (CUR_DEBUG & STAGE_RESULT_PRINT) > 0
	print(*a, *b, iprinter);
	#endif
	if (turns != -1)
		return (turns);
	while (params.asz > 3)
		turns += send_cheapest(&params, find_cheapest(&params, 0), 0);
	turns += three(params.a);
	turns += pour_into_a(&params);
	#if (CUR_DEBUG & STAGE_RESULT_PRINT) > 0
	print(*a, *b, iprinter);
	#endif
	return (turns + 2);
}
