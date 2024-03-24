/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:28:14 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/24 13:22:24 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static int	my_atoi(char **c, int *err)
{
	long	curval;
	int		sign;

	curval = 0;
	sign = 1;
	*err = 1;
	while (**c == ' ' || **c == '+' || **c == '-')
	{
		if (**c == '-')
			sign = -sign;
		(*c)++;
	}
	while (**c >= '0' && **c <= '9')
	{
		curval = curval * 10 + *((*c)++) - '0';
		*err = 0;
		if ((sign > 0 && curval > INT_MAX) || (sign < 0 && - curval < INT_MIN))
		{
			(*err) = 1;
			return (0);
		}
	}
	if (**c != ' ' && **c != '\0')
		(*err) = 1;
	return (sign * curval);
}

static int	make_node(t_dlist **a, int curval)
{
	t_dlist	*cur;

	cur = 0;
	if (a)
		cur = *a;
	while (cur)
	{
		if ((int)(intptr_t)cur->content == curval)
			return (1);
		cur = cur->next;
	}
	cur = ft_dlist_new((void *)(intptr_t)curval);
	if (!cur)
		return (1);
	ft_dlist_add_back(a, cur);
	return (0);
}

int	parse_params(t_dlist **a, int argc, char **argv)
{
	int		curval;
	int		curarg;
	int		err;

	curarg = 0;
	while (++ curarg < argc)
	{
		if (*(argv[curarg]) == '"')
			(argv[curarg])++;
		while (*argv[curarg])
		{
			curval = my_atoi(&(argv[curarg]), &err);
			if (err || make_node(a, curval))
				return (ft_dlist_clear(a, 0, 0));
		}
	}
	(*a)->prev = ft_dlist_last(*a);
	(*a)->prev->next = *a;
	return (ft_dlist_size(*a));
}

int	error(int ret, t_dlist **a, t_dlist **b)
{
	ft_dlist_clear(a, 0, 0);
	ft_dlist_clear(b, 0, 0);
	ft_fprintf(2, "Error\n");
	return (ret);
}
