/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/10 18:14:46 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

int	errors(void);
int	op_tests(void);
int	sort_turk_price_tests(void);

int	main(void)
{
	errors();
	op_tests();
	sort_turk_price_tests();
	return (0);
}
