/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:38 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 21:39:23 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static void	op_revr(t_dlist **root)
{
	if (*root)
		*root = (*root)->prev;
}

void	op_rra(t_dlist **a)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("rra\n");
	op_revr(a);
}

void	op_rrb(t_dlist **b)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("rrb\n");
	op_revr(b);
}

void	op_rrr(t_dlist **a, t_dlist **b)
{
	if ((CUR_DEBUG & 32) > 0)
		ft_printf("rrr\n");
	op_revr(a);
	op_revr(b);
}
