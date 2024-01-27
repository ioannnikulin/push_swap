/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 22:25:44 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap_internal.h"

typedef enum eOP {
	PA, PB, SA, SB, SS, RA, RB, RR, RRA, RRB, RRR
}	OP;

void go(t_dlist **a, t_dlist **b)
{
	char s[255];

	ft_printf("> ");
	scanf("%s", s);
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
	/*
	while (1)
	{
		go(a, b);
		print(*a, *b, iprinter);
	}
	*/
}
/*
static int	frbs(int what, t_dlist *br)
{
	(void)what;
	if (ft_dlist_ncmp_i(br, br->next, 1) > 0)
		return (0);
	return (0);
}

static int	price_total(t_dlist *ar, t_dlist *br, int n)
{
	t_dlist	*c;
	int		ras;
	int		rbs;
	int		rras;
	int		rrbs;

	ras = n;
	rras = ft_dlist_size(ar);
	rbs = 0;
	(void)br;
	(void)c;
	rrbs = 0;
	rras = 0;
	return (0);
}
*/
static int	three(t_dlist **a)
{
	(void)a;
	return (0);
}

static int	sorted_impl(t_dlist *a, t_dlist *root)
{
	if (a->next == root)
		return (1);
	if (ft_voidptr_icmp(a->content, a->next->content) < 0)
		return (0);
	return (sorted_impl(a->next, root));
}

static int	sorted(t_dlist *root)
{
	return (sorted_impl(root->next, root));
}
/*
static int	*calc_prices(t_dlist *a, int sza, t_dlist *b)
{
	(void)a;
	(void)b;
	(void)sza;
	return (0);
}
*/
static int	pour_into_a(t_dlist **a, t_dlist **b)
{
	(void)a;
	(void)b;
	return(0);
}

int	sort(t_dlist **a, t_dlist **b)
{
	int	asz;
	int	*prices;

	asz = ft_dlist_size(*a);
	if (asz < 2 || sorted(*a))
		return (0);
	if (asz < 4)
		return (three(a));
	op_pb(a, b);
	if (sorted(*a))
		return (1 + pour_into_a(a, b));
	op_pb(a, b);
	if (sorted(*a))
		return (2 + pour_into_a(a, b));
	asz -= 2;
	prices = malloc(asz * sizeof(int));
	if (!prices)
		return (error(0, a, b, 0));
	return (0);
}
