/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/25 20:44:38 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

t_turk_rots	find_cheapest(t_turk_params *p);

static int	three(t_turk_params *p)
{
	(void)a; // TODO:
	return (0);
}

static int	pour_into_a(t_turk_params *p)
{
	(void)a; // TODO:
	(void)b;
	return(0);
}

static int	debut(t_turk_params *p)
{
	if (p->asz < 2 || sorted(*(p->a)))
		return (0);
	if (p->asz == 2)
	{
		op_sa(p->a);
		return (1);
	}
	if (p->asz == 3)
		return (three(p));
	op_pb(p->a, p->b);
	bsz ++;
	asz --;
	if (sorted(p->a))
		return (1 + pour_into_a(p));
	op_pb(p->a, p->b);
	bsz ++;
	asz --;
	if (sorted(*(p->a)))
		return (2 + pour_into_a(p));
	return (-1);
}

int	send_cheapest(t_turk_params *p, t_turk_rots *rs)
{
	if (rs->direct_total < rs->rev_total)
	{
		while (rs->ras --)
			op_ra(p->a);
		while (rs->rbs --)
			op_rb(p->b);
		while (rs->rrs --)
			op_rr(p->a, p->b);
	}
	else
	{
		while (rs->rras --)
			op_rra(p->a);
		while (rs->rrbs --)
			op_rrb(p->b);
		while (rs->rrrs --)
			op_rrr(p->a, p->b);
	}
	op_pb(p->a, p->b);
	p->asz --;
	p->bsz ++;
	return (*ft_min_int(&(rs->rev_total), &(rs->direct_total)) + 1);
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
	if (turns != -1)
		return (turns);
	params.asz -= 2;
	params.prices = malloc(params.asz * sizeof(int));
	if (!params.prices)
		return (error(0, &params));
	while (params.asz > 3)
		turns += send_cheapest(&params, find_cheapest(&params, 0));
	turns += three(p);
	turns += pour_into_a(p);
	return (turns + 2);
}
