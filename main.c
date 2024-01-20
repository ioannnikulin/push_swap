/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:28:14 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 18:38:17 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "libft/libft.h"

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
		if ((sign > 0 && curval > INT_MAX) || (sign < 0 && -curval < INT_MIN))
			(*err) = 1;
	}
	if (**c != ' ' && **c != '\0')
		(*err) = 1;
	return (sign * curval);
}

static int	make_node(t_dlist **a, int curval)
{
	int		*content;
	t_dlist	*cur;

	cur = *a;
	while (cur)
	{
		if (*(int *)cur->content == curval)
			return (1);
		cur = cur->next;
	}
	content = malloc(sizeof(int));
	if (!content)
		return (1);
	*content = curval;
	ft_dlist_add_back(a, ft_dlist_new(content));
	return (0);
}

static int	parse_params(t_dlist **a, int argc, char **argv)
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
				return (ft_dlist_clear(a, free, 0));
		}
	}
	(*a)->prev = ft_dlist_last(*a);
	(*a)->prev->next = *a;
	return (ft_dlist_size(*a));
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;

	a = 0;
	b = 0;
	if (argc == 1 || !parse_params(&a, argc, argv))
	{
		ft_fprintf(2, "Error\n");
		return (0);
	}
	ft_dlist_print(a, 31, "\n");
	//sort(&a, &b);
	return (0);
}
