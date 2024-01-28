/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_manual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:06:31 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/28 17:08:43 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	go(t_dlist **a, t_dlist **b)
{
	char s[255];

	ft_printf("> ");
	scanf("%s", s); // TODO: replace scanf with gnl, split for function lengths
	if (ft_strncmp(s, "pa", 2) == 0)
		op_pa(a, b);
	else if (ft_strncmp(s, "pb", 2) == 0)
		op_pb(a, b);
	else if (ft_strncmp(s, "ra", 2) == 0)
		op_ra(a);
	else if (ft_strncmp(s, "rb", 2) == 0)
		op_rb(b);
	else if (ft_strncmp(s, "rr", 2) == 0)
		op_rr(a, b);
	else if (ft_strncmp(s, "sa", 2) == 0)
		op_sa(a);
	else if (ft_strncmp(s, "sb", 2) == 0)
		op_sb(b);
	else if (ft_strncmp(s, "ss", 2) == 0)
		op_ss(a, b);
	else if (ft_strncmp(s, "rra", 3) == 0)
		op_rra(a);
	else if (ft_strncmp(s, "rrb", 3) == 0)
		op_rrb(b);
	else if (ft_strncmp(s, "rrr", 3) == 0)
		op_rrr(a, b);
	else
		ft_printf("Operation not recognized\n");
}

void	sort_manual(t_dlist **a, t_dlist **b)
{
	while (1)
	{
		go(a, b);
		print(*a, *b, iprinter);
	}
}
