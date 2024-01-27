/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 21:38:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static void	op_r(t_dlist **root)
{
	if (*root)
		*root = (*root)->next;
}

void	op_ra(t_dlist **a)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("ra\n");
	op_r(a);
}

void	op_rb(t_dlist **b)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("rb\n");
	op_r(b);
}

void	op_rr(t_dlist **a, t_dlist **b)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("rr\n");
	op_r(a);
	op_r(b);
}
