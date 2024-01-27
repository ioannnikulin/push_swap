/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 15:08:16 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap_internal.h"
#define CUR_DEBUG MAX_DEBUG

int	errors(int debug_lvl);
int op_tests(int debug_lvl);

int	main(void)
{
	errors(CUR_DEBUG);
	op_tests(CUR_DEBUG);
	return (0);
}
