/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 20:57:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap_internal.h"

typedef enum eOP {
	PA, PB, SA, SB, SS, RA, RB, RR, RRA, RRB, RRR
}	OP;

void go(t_dlist **a, t_dlist **b, int debug_lvl)
{
	char s[255];

	ft_printf("> ");
	scanf("%s", s);
	if (ft_strncmp(s, "pa", 2) == 0)
		op_pa(a, b, debug_lvl);
	else if (ft_strncmp(s, "pb", 2) == 0)
		op_pb(a, b, debug_lvl);
	else if (ft_strncmp(s, "ra", 2) == 0)
		op_ra(a, debug_lvl);
	else if (ft_strncmp(s, "rb", 2) == 0)
		op_rb(b, debug_lvl);
	else if (ft_strncmp(s, "rr", 2) == 0)
		op_rr(a, b, debug_lvl);
	else if (ft_strncmp(s, "sa", 2) == 0)
		op_sa(a, debug_lvl);
	else if (ft_strncmp(s, "sb", 2) == 0)
		op_sb(b, debug_lvl);
	else if (ft_strncmp(s, "ss", 2) == 0)
		op_ss(a, b, debug_lvl);
	else if (ft_strncmp(s, "rra", 3) == 0)
		op_rra(a, debug_lvl);
	else if (ft_strncmp(s, "rrb", 3) == 0)
		op_rrb(b, debug_lvl);
	else if (ft_strncmp(s, "rrr", 3) == 0)
		op_rrr(a, b, debug_lvl);
	else
		ft_printf("Operation not recognized\n");
}

int	sort(t_dlist **a, t_dlist **b, int debug_lvl)
{
	while (1)
	{
		go(a, b, debug_lvl);
		print(*a, *b, debug_lvl, iprinter);
	}
	return (0);
}
