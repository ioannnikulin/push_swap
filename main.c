/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:28:14 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/02 17:08:04 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

int	parse_params(t_dlist **a, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist	*b;
	int		ops;

	a = 0;
	b = 0;
	if (argc == 1 || !parse_params(&a, argc, argv))
		return (error(0, 0, 0, 0));
	print(a, b, iprinter);
	ops = sort(&a, &b);
	#if (CUR_DEBUG & OPS_COUNT_TOTAL) > 0
	ft_printf("Total operations: %i\n", ops);
	#endif
	return (0);
}
