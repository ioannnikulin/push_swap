/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:28:14 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 22:26:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"
#define CUR_DEBUG MANUAL_OPS

int	parse_params(t_dlist **a, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;

	a = 0;
	b = 0;
	if (argc == 1 || !parse_params(&a, argc, argv))
		return (error(0, 0, 0, 0));
	print(a, b, iprinter);
	sort(&a, &b);
	return (0);
}
