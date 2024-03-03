/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/03 20:50:25 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

int	errors(void);
int	op_tests(void);
int	sort_turk_price_tests(void);
int	sort_turk_threes_tests(void);
int	sort_mark_lis_tests(void);
int	performance_tests(void);

int	main(void)
{
	/*errors();
	op_tests();
	sort_turk_price_tests();
	sort_turk_threes_tests();
	sort_mark_lis_tests();*/
	performance_tests();
	return (0);
}
