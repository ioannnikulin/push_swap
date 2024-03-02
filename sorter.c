/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/02 15:47:18 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"
#ifdef TURK
int	sort_turk(t_dlist **a, t_dlist **b);
#endif
#ifdef MANUAL
int	sort_manual(t_dlist **a, t_dlist **b);
#endif

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
