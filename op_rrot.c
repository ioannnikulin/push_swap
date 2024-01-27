/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 18:17:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static void	op_revr(t_dlist **root, int debug_lvl)
{
	(void)debug_lvl;
	if (*root)
		*root = (*root)->prev;
}

void	op_rra(t_dlist **a, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("rra\n");
	op_revr(a, debug_lvl);
}

void	op_rrb(t_dlist **b, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("rrb\n");
	op_revr(b, debug_lvl);
}

void	op_rrr(t_dlist **a, t_dlist **b, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("rrr\n");
	op_revr(a, debug_lvl);
	op_revr(b, debug_lvl);
}
