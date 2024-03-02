/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/02 18:42:03 by inikulin         ###   ########.fr       */
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
	return (sort_turk(a, b));
	#endif
	#ifdef MANUAL
	return (sort_manual(a, b));
	#endif
	(void)a;
	(void)b;
	return (0);
}
