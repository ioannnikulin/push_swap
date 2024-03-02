/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_threes_tests.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/03/02 15:47:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "sort_turk_internal.h"
#define START 0 
#define SZ 6

int	three(t_dlist **a);

void	sort_turk_threes_tests()
{
	t_dlist *a;
	int *t[SZ];
	t[0]=(int[]){1,2,3};
	t[1]=(int[]){1,3,2};
	t[2]=(int[]){2,1,3};
	t[3]=(int[]){2,3,1};
	t[4]=(int[]){3,2,1};
	t[5]=(int[]){3,1,2};
	printf("Starting %d tests of three nodes fast-sorting.\n", SZ - START);
	for (int i = START; i < SZ; i ++)
	{
		if ((CUR_DEBUG & OP_TEST_BORDER) > 0)
			printf("\n################################################################\n\n");
		if ((CUR_DEBUG & OP_TEST_NUMBERS) > 0)
			printf("test #%i\n", i);
		a = ft_dlist_generate_int(t[i], 3, 0);
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0)
		{
			printf("SOURCE:\n");
			assert(print(a, 0, iprinter) == 0);
		}
		three(&a);
		int more = (ft_voidptr_icmp(a->content, a->next->content) > 0) + \
					(ft_voidptr_icmp(a->next->content, a->next->next->content) > 0) + \
					(ft_voidptr_icmp(a->next->next->content, a->content) > 0);
		assert(more == 1);
		ft_dlist_clear(&a, 0, 0);
	}
	printf("SUCCESS: all operations performed as predicted\n");
}
