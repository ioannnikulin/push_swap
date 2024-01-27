/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:28:14 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 19:26:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"
#define CUR_DEBUG MAX_DEBUG

int	parse_params(t_dlist **a, int argc, char **argv);

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
	print(a, b, CUR_DEBUG, iprinter);
	op_sa(&a, CUR_DEBUG);
	print(a, b, CUR_DEBUG, iprinter);
	op_pb(&a, &b, CUR_DEBUG);
	print(a, b, CUR_DEBUG, iprinter);

	//sort(&a, &b);
	return (0);
}
