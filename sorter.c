/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/24 15:54:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"
int	checker(t_dlist **a, t_dlist **b);
int	sort_turk(t_dlist **a, t_dlist **b);

int	sort(t_dlist **a, t_dlist **b)
{
	if (CHECKER)
		return (checker(a, b));
	return (sort_turk(a, b));
}
