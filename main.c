/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:28:14 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 20:19:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"
#define CUR_DEBUG MAX_DEBUG

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

void	print(t_dlist *a, t_dlist *b, int debug_lvl)
{
	char delim[2];

	delim[0] = ' ';
	delim[1] = 0;
	if ((debug_lvl & BORDER_PRINTOUT) > 0)
		ft_printf("\n================================");
	if ((debug_lvl & NEWLINE_BETWEEN_ELEMENTS) > 0)
		delim[0] = '\n';
	if ((debug_lvl & STACK_HEADER_FOOTER) > 0)
		ft_printf("\nStack A:\n");
	ft_dlist_print(a, debug_lvl, delim);
	if ((debug_lvl & STACK_HEADER_FOOTER) > 0)
		ft_printf("--------\n");
	if ((debug_lvl & STACK_HEADER_FOOTER) > 0)
		ft_printf("\nStack B:\n");
	ft_dlist_print(b, debug_lvl, delim);
	if ((debug_lvl & STACK_HEADER_FOOTER) > 0)
		ft_printf("--------\n");
	if ((debug_lvl & BORDER_PRINTOUT) > 0)
		ft_printf("\n================================");
	ft_printf("\n");
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
	print(a, b, 0);
	op_sa(&a, 0);
	print(a, b, 0);
	op_pb(&a, &b, 0);
	print(a, b, 0);

	//sort(&a, &b);
	return (0);
}