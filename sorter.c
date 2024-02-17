/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/17 18:39:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"
#ifdef TURK
int	sort_turk(t_dlist **a, t_dlist **b);
#endif
#ifdef MANUAL
int	sort_manual(t_dlist **a, t_dlist **b);
#endif

static int	sorted_impl(t_dlist *a, t_dlist *root)
{
	if (a->next == root)
		return (1);
	if (ft_voidptr_icmp(a->content, a->next->content) < 0)
		return (0);
	return (sorted_impl(a->next, root));
}

int	sorted(t_dlist *root)
{
	return (sorted_impl(root->next, root));
}

int	sort(t_dlist **a, t_dlist **b)
{
	#ifdef TURK
	ft_printf("TURK\n");
	return (sort_turk(a, b));
	#endif
	#ifdef MANUAL
	ft_printf("MANUAL\n");
	return (sort_manual(a, b));
	#endif
	ft_printf("NUFFIN\n");
	(void)a;
	(void)b;
	return (0);
}
