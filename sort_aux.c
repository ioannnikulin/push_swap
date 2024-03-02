/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:43:32 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/02 16:51:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

int	three(t_dlist **a)
{
	int	c1;
	int	c2;
	int	c3;

	c1 = ft_voidptr_icmp((*a)->content, (*a)->next->content);
	c2 = ft_voidptr_icmp((*a)->next->content, (*a)->next->next->content);
	c3 = ft_voidptr_icmp((*a)->content, (*a)->next->next->content);
	if ((c1 < 0 && c2 < 0 && c3 < 0) || (c3 > 0 && ((c1 > 0) != (c2 > 0))))
		return (0);
	if ((c1 > 0 && c2 > 0) || (c1 < 0 && c2 > 0 && c3 < 0) \
		|| (c1 > 0 && c2 < 0))
	{
		op_sa(a);
		return (1);
	}
	op_rra(a);
	op_sa(a);
	return (2);
}

static int	sorted_impl(t_dlist *a, t_dlist *root)
{
	if (a->next == root)
		return (0);
	if (ft_voidptr_icmp(a->content, a->next->content) > 0)
		return (0);
	return (1 + sorted_impl(a->next, root));
}

int	sorted(t_dlist *root)
{
	return (1 + sorted_impl(root, root));
}
