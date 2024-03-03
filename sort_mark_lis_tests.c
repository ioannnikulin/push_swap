/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mark_lis_tests.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/03/03 14:42:58 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "sort_turk_internal.h"
#define START 0 
#define SZ 37

typedef struct s_testcase {
	int	*a;
	int	asz;
	int	*exp;
	int	expsz;
}	t_testcase;

int	mark_lis(t_dlist *a, int asz);

void	sort_turk_price_tests()
{
	t_dlist *a;
	t_testcase t[SZ];
	t[0]=(t_testcase){(int[]){0,1,2,0,1,3},6,(int[]){0,1,2,3}, 4};
	printf("Starting %d longest increasing subsequence search tests tests.\n", SZ - START);
	for (int i = START; i < SZ; i ++)
	{
		if ((CUR_DEBUG & OP_TEST_BORDER) > 0)
			printf("\n################################################################\n\n");
		if ((CUR_DEBUG & OP_TEST_NUMBERS) > 0)
			printf("test #%i\n", i);
		a = ft_dlist_generate_int(t[i].a, t[i].asz, 0);
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0)
		{
			printf("SOURCE:\n");
			assert(print(a, 0, iprinter) == 0);
			printf(t[i].toa ? "from B to A\n" : "from A to B\n");
			printf("PRICES EXP / ACTUAL:\n");
			printprices(t[i].exp, act, 1);
		}
		else
			printprices(t[i].exp, act, 0);
		ft_dlist_clear(&a, 0, 0);
		ft_dlist_clear(&b, 0, 0);
	}
	printf("SUCCESS: all operations performed as predicted\n");
}
