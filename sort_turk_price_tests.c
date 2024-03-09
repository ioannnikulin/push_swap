/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/03/09 18:06:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "sort_turk_internal.h"
#define START 26 
#define SZ 37

typedef struct s_testcase {
	int	*a;
	int	asz;
	int	*b;
	int	bsz;
	int	toa;
	t_turk_rots exp;
}	t_testcase;

static void printprices(t_turk_rots exp, t_turk_rots act, int print)
{
	if (print)
	{
		printf("ra: %i %i\n", exp.ras, act.ras);
		printf("rb: %i %i\n", exp.rbs, act.rbs);
		printf("rr: %i %i\n", exp.rrs, act.rrs);
		printf("rra: %i %i\n", exp.rras, act.rras);
		printf("rrb: %i %i\n", exp.rrbs, act.rrbs);
		printf("rrr: %i %i\n", exp.rrrs, act.rrrs);
		printf("total: %i %i\n", exp.total, act.total);
	}
	assert(exp.ras == act.ras);
	assert(exp.rbs == act.rbs);
	assert(exp.rrs == act.rrs);
	assert(exp.rras == act.rras);
	assert(exp.rrbs == act.rrbs);
	assert(exp.rrrs == act.rrrs);
	assert(exp.total == act.total);
}

t_turk_rots	find_cheapest(t_turk_params *p, int toa);

void	sort_turk_price_tests()
{
	t_dlist *a, *b;
	t_testcase t[SZ];
	t[0]=(t_testcase){(int[]){5},1,(int[]){4,3,2,1}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[1]=(t_testcase){(int[]){5},1,(int[]){3,2,1,4}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 1, 0, 2}};
	t[2]=(t_testcase){(int[]){5},1,(int[]){2,1,4,3}, 4, 0,	(t_turk_rots){0,0,0, 2, 0, 0, 0, 0, 3}};
	t[3]=(t_testcase){(int[]){5},1,(int[]){1,4,3,2}, 4, 0,	(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	t[4]=(t_testcase){(int[]){4},1,(int[]){5,3,2,1}, 4, 0,	(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	t[5]=(t_testcase){(int[]){4},1,(int[]){3,2,1,5}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[6]=(t_testcase){(int[]){4},1,(int[]){2,1,5,3}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 1, 0, 2}};
	t[7]=(t_testcase){(int[]){4},1,(int[]){1,5,3,2}, 4, 0,	(t_turk_rots){0,0,0, 2, 0, 0, 0, 0, 3}};
	t[8]=(t_testcase){(int[]){3},1,(int[]){5,4,2,1}, 4, 0,	(t_turk_rots){0,0,0, 2, 0, 0, 0, 0, 3}};
	t[9]=(t_testcase){(int[]){3},1,(int[]){4,2,1,5}, 4, 0,	(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	t[10]=(t_testcase){(int[]){3},1,(int[]){2,1,5,4}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[11]=(t_testcase){(int[]){3},1,(int[]){1,5,4,2}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 1, 0, 2}};
	t[12]=(t_testcase){(int[]){2},1,(int[]){5,4,3,1}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 1, 0, 2}};
	t[13]=(t_testcase){(int[]){2},1,(int[]){4,3,1,5}, 4, 0,	(t_turk_rots){0,0,0, 2, 0, 0, 0, 0, 3}};
	t[14]=(t_testcase){(int[]){2},1,(int[]){3,1,5,4}, 4, 0,	(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	t[15]=(t_testcase){(int[]){2},1,(int[]){1,5,4,3}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[16]=(t_testcase){(int[]){1},1,(int[]){5,4,3,2}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[17]=(t_testcase){(int[]){1},1,(int[]){4,3,2,5}, 4, 0,	(t_turk_rots){0,0,0, 0, 0, 0, 1, 0, 2}};
	t[18]=(t_testcase){(int[]){1},1,(int[]){3,2,5,4}, 4,0,	(t_turk_rots){0,0,0, 2, 0, 0, 0, 0, 3}};
	t[19]=(t_testcase){(int[]){1},1,(int[]){2,5,4,3}, 4, 0,	(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	t[20]=(t_testcase){(int[]){3},1,(int[]){2,1},2,0,		(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[21]=(t_testcase){(int[]){3},1,(int[]){1,2},2,0,		(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	t[22]=(t_testcase){(int[]){2},1,(int[]){3,1},2,0,		(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	t[23]=(t_testcase){(int[]){2},1,(int[]){1,3},2,0,		(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[24]=(t_testcase){(int[]){1},1,(int[]){3,2},2,0,		(t_turk_rots){0,0,0, 0, 0, 0, 0, 0, 1}};
	t[25]=(t_testcase){(int[]){1},1,(int[]){2,3},2,0,		(t_turk_rots){0,0,0, 1, 0, 0, 0, 0, 2}};
	//																	obj,offset ra rb rr rra rrb rrr tot
	t[26]=(t_testcase){(int[]){5,2},2,(int[]){7,6,4,3,0},5,0,	 (t_turk_rots){0,0,0, 0, 0,  0,  0,  1,  2}};
	t[27]=(t_testcase){(int[]){1,6,3,9,4,8},6,(int[]){7,5,2},3,0,(t_turk_rots){0,0,0, 0, 0,  0,  0,  0,  1}};
	t[28]=(t_testcase){(int[]){6,3,9,4,8},5,(int[]){1,7,5,2},4,0,(t_turk_rots){0,0,0, 2, 0,  0,  0,  0,  3}};
	t[29]=(t_testcase){(int[]){3,9,4,8},4,(int[]){6,5,2,1,7},5,0,(t_turk_rots){0,0,0, 2, 0,  0,  0,  0,  3}};
	t[30]=(t_testcase){(int[]){3,9,4},3,(int[]){8,7,6,5,2,1},6,0,(t_turk_rots){0,0,1, 0, 0,  0,  0,  0,  2}};
	t[31]=(t_testcase){(int[]){0,3,4,6,7},5,(int[]){5,2},2,1,	 (t_turk_rots){0,0,0, 0, 1,  0,  0,  0,  2}};
	t[32]=(t_testcase){(int[]){2,5,7},3,(int[]){1,6,3,9,4,8},6,1,(t_turk_rots){0,0,0, 0, 0,  0,  0,  0,  1}};
	t[33]=(t_testcase){(int[]){2,5,7,1},4,(int[]){6,3,9,4,8},5,1,(t_turk_rots){0,0,0, 0, 1,  0,  0,  0,  2}};
	t[34]=(t_testcase){(int[]){7,1,2,5,6},5,(int[]){3,9,4,8},4,1,(t_turk_rots){0,0,0, 0, 1,  0,  0,  0,  2}};
	t[35]=(t_testcase){(int[]){1,2,5,6,7,8},6,(int[]){3,9,4},3,1,(t_turk_rots){0,0,0, 1, 0,  0,  0,  0,  2}};
	t[36]=(t_testcase){(int[]){1,2,4},3,(int[]){3},1,1,			 (t_turk_rots){0,0,0, 0, 0,  1,  0,  0,  2}};
	printf("Starting %d TurkSort price-estimation tests.\n", SZ - START);
	for (int i = START; i < SZ; i ++)
	{
		if ((CUR_DEBUG & OP_TEST_BORDER) > 0)
			printf("\n################################################################\n\n");
		if ((CUR_DEBUG & OP_TEST_NUMBERS) > 0)
			printf("test #%i\n", i);
		a = ft_dlist_generate_int(t[i].a, t[i].asz, 0);
		b = ft_dlist_generate_int(t[i].b, t[i].bsz, 0);
		t_turk_rots act = find_cheapest(&(t_turk_params){&a, &b, t[i].asz, t[i].bsz, 0}, t[i].toa);
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0)
		{
			printf("SOURCE:\n");
			assert(print(a, b, iprinter) == 0);
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
