/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 21:36:49 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static void	op_p(t_dlist **from, t_dlist **to)
{
	int		sz;
	t_dlist	*a;

	sz = ft_dlist_size(*from);
	if (sz < 1)
		return ;
	a = *from;
	if (sz == 1)
		*from = 0;
	else
	{
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		*from = (*from)->next;
	}
	a->prev = 0;
	a->next = 0;
	ft_dlist_add_front(to, a);
	if (ft_dlist_size(*to) == 1)
	{
		a->prev = a;
		a->next = a;
	}
}

void	op_pa(t_dlist **a, t_dlist **b)
{
	if ((CUR_DEBUG & OP_NAME) > 0)
		ft_printf("pa\n");
	op_p(b, a);
}

void	op_pb(t_dlist **a, t_dlist **b)
{
	if ((CUR_DEBUG & OP_NAME) > 0)
		ft_printf("pb\n");
	op_p(a, b);
}
