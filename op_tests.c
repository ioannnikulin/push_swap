/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/02/10 18:14:08 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "push_swap_internal.h"
#define START 0
#define SZ 55

typedef struct s_testcase {
	char	*a[10];
	char	*b[10];
	t_OP	ops[10];
	int opsz;
	char	*expa[10];
	char	*expb[10];
}	t_testcase;

void	op_tests()
{
	t_dlist *a, *b;
	t_testcase t[SZ];
	t[0] = (t_testcase){{"1", "2", "3", NULL}, {"4", "5", "6", "7", NULL}, {PB}, 1, {"2", "3", NULL}, {"1", "4", "5", "6", "7", NULL}};
	t[1] = (t_testcase){{"1", NULL}, {"4", "5", "6", "7", NULL}, {PB}, 1, {NULL}, {"1", "4", "5", "6", "7", NULL}};
	t[2] = (t_testcase){{NULL}, {"4", "5", "6", "7", NULL}, {PB}, 1, {NULL}, {"4", "5", "6", "7", NULL}};
	t[3] = (t_testcase){{"1", NULL}, {"7", NULL}, {PB}, 1, {NULL}, {"1", "7", NULL}};
	t[4] = (t_testcase){{"1", NULL}, {NULL}, {PB}, 1, {NULL}, {"1", NULL}};
	t[5] = (t_testcase){{NULL}, {"1", NULL}, {PB}, 1, {NULL}, {"1", NULL}};
	t[6] = (t_testcase){{NULL}, {NULL}, {PB}, 1, {NULL}, {NULL}};
	t[7] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", "2", "3", NULL}, {PA}, 1, {"1", "4", "5", "6", "7", NULL}, {"2", "3", NULL}};
	t[8] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", NULL}, {PA}, 1, {"1", "4", "5", "6", "7", NULL}, {NULL}};
	t[9] = (t_testcase){{"4", "5", "6", "7", NULL}, {NULL}, {PA}, 1, {"4", "5", "6", "7", NULL}, {NULL}};
	t[10] = (t_testcase){{"7", NULL}, {"1", NULL}, {PA}, 1, {"1", "7", NULL}, {NULL}};
	t[11] = (t_testcase){{"1", NULL}, {NULL}, {PA}, 1, {"1", NULL}, {NULL}};
	t[12] = (t_testcase){{NULL}, {"1", NULL}, {PA}, 1, {"1", NULL}, {NULL}};
	t[13] = (t_testcase){{NULL}, {NULL}, {PA}, 1, {NULL}, {NULL}};
	t[14] = (t_testcase){{"1", "2", "3", NULL}, {"4", "5", "6", "7", NULL}, {RA}, 1, {"2", "3", "1", NULL}, {"4", "5", "6", "7", NULL}};
	t[15] = (t_testcase){{"1", NULL}, {"4", "5", "6", "7", NULL}, {RA}, 1, {"1", NULL}, {"4", "5", "6", "7", NULL}};
	t[16] = (t_testcase){{NULL}, {"4", "5", "6", "7", NULL}, {RA}, 1, {NULL}, {"4", "5", "6", "7", NULL}};
	t[17] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", "2", "3", NULL}, {RB}, 1, {"4", "5", "6", "7", NULL}, {"2", "3", "1", NULL}};
	t[18] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", NULL}, {RB}, 1, {"4", "5", "6", "7", NULL}, {"1", NULL}};
	t[19] = (t_testcase){{"4", "5", "6", "7", NULL}, {NULL}, {RB}, 1, {"4", "5", "6", "7", NULL}, {NULL}};
	t[20] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", "2", "3", NULL}, {RR}, 1, {"5", "6", "7", "4", NULL}, {"2", "3", "1", NULL}};
	t[21] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", NULL}, {RR}, 1, {"5", "6", "7", "4", NULL}, {"1", NULL}};
	t[22] = (t_testcase){{"4", "5", "6", "7", NULL}, {NULL}, {RR}, 1, {"5", "6", "7", "4", NULL}, {NULL}};
	t[23] = (t_testcase){{"1", NULL}, {"4", "5", "6", "7", NULL}, {RR}, 1, {"1", NULL}, {"5", "6", "7", "4", NULL}};
	t[24] = (t_testcase){{NULL}, {"4", "5", "6", "7", NULL}, {RR}, 1, {NULL}, {"5", "6", "7", "4", NULL}};
	t[25] = (t_testcase){{NULL}, {NULL}, {RR}, 1, {NULL}, {NULL}};
	t[26] = (t_testcase){{"2", "3", "1", NULL}, {"4", "5", "6", "7", NULL}, {RRA}, 1, {"1", "2", "3", NULL}, {"4", "5", "6", "7", NULL}};
	t[27] = (t_testcase){{"1", NULL}, {"4", "5", "6", "7", NULL}, {RRA}, 1, {"1", NULL}, {"4", "5", "6", "7", NULL}};
	t[28] = (t_testcase){{NULL}, {"4", "5", "6", "7", NULL}, {RRA}, 1, {NULL}, {"4", "5", "6", "7", NULL}};
	t[29] = (t_testcase){{"4", "5", "6", "7", NULL}, {"2", "3", "1", NULL}, {RRB}, 1, {"4", "5", "6", "7", NULL}, {"1", "2", "3", NULL}};
	t[30] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", NULL}, {RRB}, 1, {"4", "5", "6", "7", NULL}, {"1", NULL}};
	t[31] = (t_testcase){{"4", "5", "6", "7", NULL}, {NULL}, {RRB}, 1, {"4", "5", "6", "7", NULL}, {NULL}};
	t[32] = (t_testcase){{"5", "6", "7", "4", NULL}, {"2", "3", "1", NULL}, {RRR}, 1, {"4", "5", "6", "7", NULL}, {"1", "2", "3", NULL}};
	t[33] = (t_testcase){{"5", "6", "7", "4", NULL}, {"1", NULL}, {RRR}, 1, {"4", "5", "6", "7", NULL}, {"1", NULL}};
	t[34] = (t_testcase){{"5", "6", "7", "4", NULL}, {NULL}, {RRR}, 1, {"4", "5", "6", "7", NULL}, {NULL}};
	t[35] = (t_testcase){{"1", NULL}, {"5", "6", "7", "4", NULL}, {RRR}, 1, {"1", NULL}, {"4", "5", "6", "7", NULL}};
	t[36] = (t_testcase){{NULL}, {"5", "6", "7", "4", NULL}, {RRR}, 1, {NULL}, {"4", "5", "6", "7", NULL}};
	t[37] = (t_testcase){{NULL}, {NULL}, {RRR}, 1, {NULL}, {NULL}};
	t[38] = (t_testcase){{"1", "2", "3", NULL}, {"4", "5", "6", "7", NULL}, {SA}, 1, {"2", "1", "3", NULL}, {"4", "5", "6", "7", NULL}};
	t[39] = (t_testcase){{"1", NULL}, {"4", "5", "6", "7", NULL}, {SA}, 1, {"1", NULL}, {"4", "5", "6", "7", NULL}};
	t[40] = (t_testcase){{NULL}, {"4", "5", "6", "7", NULL}, {SA}, 1, {NULL}, {"4", "5", "6", "7", NULL}};
	t[41] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", "2", "3", NULL}, {SB}, 1, {"4", "5", "6", "7", NULL}, {"2", "1", "3", NULL}};
	t[42] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", NULL}, {SB}, 1, {"4", "5", "6", "7", NULL}, {"1", NULL}};
	t[43] = (t_testcase){{"4", "5", "6", "7", NULL}, {NULL}, {SB}, 1, {"4", "5", "6", "7", NULL}, {NULL}};
	t[44] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", "2", "3", NULL}, {SS}, 1, {"5", "4", "6", "7", NULL}, {"2", "1", "3", NULL}};
	t[45] = (t_testcase){{"4", "5", "6", "7", NULL}, {"1", NULL}, {SS}, 1, {"5", "4", "6", "7", NULL}, {"1", NULL}};
	t[46] = (t_testcase){{"4", "5", "6", "7", NULL}, {NULL}, {SS}, 1, {"5", "4", "6", "7", NULL}, {NULL}};
	t[47] = (t_testcase){{"1", NULL}, {"4", "5", "6", "7", NULL}, {SS}, 1, {"1", NULL}, {"5", "4", "6", "7", NULL}};
	t[48] = (t_testcase){{NULL}, {"4", "5", "6", "7", NULL}, {SS}, 1, {NULL}, {"5", "4", "6", "7", NULL}};
	t[49] = (t_testcase){{"1", NULL}, {"4", NULL}, {SS}, 1, {"1", NULL}, {"4", NULL}};
	t[50] = (t_testcase){{NULL}, {NULL}, {SS}, 1, {NULL}, {NULL}};
	t[51] = (t_testcase){{"1", "2", NULL}, {NULL}, {PB}, 1, {"2", NULL}, {"1", NULL}};
	t[52] = (t_testcase){{NULL}, {"1", "2", NULL}, {PA}, 1, {"1", NULL}, {"2", NULL}};
	t[53] = (t_testcase){{"1", "2", NULL}, {NULL}, {PB, PB}, 2, {NULL}, {"2", "1", NULL}};
	t[54] = (t_testcase){{NULL}, {"1", "2", NULL}, {PA, PA}, 2, {"2", "1", NULL}, {NULL}};
	printf("Starting %d dlist-operational tests.\n", SZ - START);
	for (int i = START; i < SZ; i ++)
	{
		if ((CUR_DEBUG & OP_TEST_BORDER) > 0)
			printf("\n################################################################\n\n");
		if ((CUR_DEBUG & OP_TEST_NUMBERS) > 0)
			printf("test #%i\n", i);
		a = ft_dlist_generate(t[i].a, 0);
		b = ft_dlist_generate(t[i].b, 0);
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0)
		{
			printf("ORIGINAL:\n");
			assert(print(a, b, sprinter) == 0);
		}
		int op = t[i].opsz;
		while (op --)
		{
			switch (t[i].ops[op])
			{
				case PA:
					op_pa(&a, &b);
					break;
				case PB:
					op_pb(&a, &b);
					break;
				case RA:
					op_ra(&a);
					break;
				case RB:
					op_rb(&b);
					break;
				case RR:
					op_rr(&a, &b);
					break;
				case SA:
					op_sa(&a);
					break;
				case SB:
					op_sb(&b);
					break;
				case SS:
					op_ss(&a, &b);
					break;
				case RRA:
					op_rra(&a);
					break;
				case RRB:
					op_rrb(&b);
					break;
				case RRR:
					op_rrr(&a, &b);
					break;
				default:
					printf("Operation not recognized\n");
					assert(0);
			}
		}
		int nsza = ft_dlist_size(a);
		int nszb = ft_dlist_size(b);
		t_dlist *expa = ft_dlist_generate(t[i].expa, 0);
		t_dlist *expb = ft_dlist_generate(t[i].expb, 0);
		int expsza = ft_dlist_size(expa);
		int expszb = ft_dlist_size(expb);
		if ((CUR_DEBUG & OP_TEST_DETAILS) > 0)
			printf("a: %i nodes (expected %i), b: %i nodes (expected %i)\n", nsza, expsza, nszb, expszb);
		int wronga = ft_dlist_ncmp_str(a, expa, expsza + 1) != 0;
		int wrongb = ft_dlist_ncmp_str(b, expb, expszb + 1) != 0;
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0 && (wronga || wrongb || (CUR_DEBUG & OP_TEST_FULLDETAILS_SUCCESS) > 0))
		{
			printf("EXPECTED:\n");
			assert(print(expa, expb, sprinter) == 0);
			printf("ACTUAL:\n");
			assert(print(a, b, sprinter) == 0);
		}
		assert(!wronga && !wrongb);
		ft_dlist_clear(&a, free, 0);
		ft_dlist_clear(&b, free, 0);
		ft_dlist_clear(&expa, free, 0);
		ft_dlist_clear(&expb, free, 0);
	}
	printf("SUCCESS: all operations performed as predicted\n");
}
