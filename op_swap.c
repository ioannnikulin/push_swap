/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 21:40:02 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static void	op_s(t_dlist **root)
{
	int	sz;
	t_dlist	*a;
	t_dlist *b;

	sz = ft_dlist_size(*root);
	if (sz < 2)
		return ;
	a = *root;
	b = (*root)->next;
	a->next = b->next;
	a->next->prev = a;
	b->next = a;
	b->prev = a->prev;
	b->prev->next = b;
	a->prev = b;
	*root = b;
}

void	op_sa(t_dlist **a)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("sa\n");
	op_s(a);
}

void	op_sb(t_dlist **b)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("sb\n");
	op_s(b);
}

void	op_ss(t_dlist **a, t_dlist **b)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("ss\n");
	op_s(a);
	op_s(b);
}
