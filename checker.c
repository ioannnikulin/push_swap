/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 13:10:20 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/24 15:53:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static int	action1(char *s, t_dlist **a, t_dlist **b)
{
	if (ft_strncmp(s, "rra", 3) == 0)
		op_rra(a);
	else if (ft_strncmp(s, "rrb", 3) == 0)
		op_rrb(b);
	else if (ft_strncmp(s, "rrr", 3) == 0)
		op_rrr(a, b);
	else if (ft_strncmp(s, "rr", 2) == 0)
		op_rr(a, b);
	else 
		return (0);
	return (1);
}

static int	action(char *s, t_dlist **a, t_dlist **b)
{
	if (ft_strncmp(s, "pa", 2) == 0)
		op_pa(a, b);
	else if (ft_strncmp(s, "pb", 2) == 0)
		op_pb(a, b);
	else if (ft_strncmp(s, "ra", 2) == 0)
		op_ra(a);
	else if (ft_strncmp(s, "rb", 2) == 0)
		op_rb(b);
	else if (ft_strncmp(s, "sa", 2) == 0)
		op_sa(a);
	else if (ft_strncmp(s, "sb", 2) == 0)
		op_sb(b);
	else if (ft_strncmp(s, "ss", 2) == 0)
		op_ss(a, b);
	else
		return (action1(s, a, b));
	return (1);
}

int	checker(t_dlist **a, t_dlist **b)
{
	char	*s;
	int		asz;

	asz = ft_dlist_size(*a);
	s = get_next_line(0);
	while (s)
	{
		if (action(s, a, b) == 0)
			return (error(0, a, b));
		free(s);
		s = get_next_line(0);
	}
	if (ft_dlist_size(*b) == 0 && sorted(*a) == asz)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}
