/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 20:12:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static void	op_s(t_dlist **root, int debug_lvl)
{
	int	sz;
	t_dlist	*a;
	t_dlist *b;

	(void)debug_lvl;
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

void	op_sa(t_dlist **a, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("sa\n");
	op_s(a, debug_lvl);
}

void	op_sb(t_dlist **b, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("sb\n");
	op_s(b, debug_lvl);
}

void	op_ss(t_dlist **a, t_dlist **b, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("ss\n");
	op_s(a, debug_lvl);
	op_s(b, debug_lvl);
}