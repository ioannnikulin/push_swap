/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 20:13:29 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static void	op_r(t_dlist **root, int debug_lvl)
{
	(void)debug_lvl;
	*root = (*root)->next;
}

void	op_ra(t_dlist **a, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("ra\n");
	op_r(a, debug_lvl);
}

void	op_rb(t_dlist **b, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("rb\n");
	op_r(b, debug_lvl);
}

void	op_rr(t_dlist **a, t_dlist **b, int debug_lvl)
{
	if ((debug_lvl & 32) > 0)
		ft_printf("rr\n");
	op_r(a, debug_lvl);
	op_r(b, debug_lvl);
}
