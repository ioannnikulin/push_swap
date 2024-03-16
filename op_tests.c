/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/03/16 21:44:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "push_swap_internal.h"
#define START 0
#define SZ 55

typedef struct s_testcase {
	int		a[10];
	int		asz;
	int		b[10];
	int		bsz;
	t_OP	ops[10];
	int opsz;
	int		expa[10];
	int		expasz;
	int		expb[10];
	int		expbsz;
}	t_testcase;

void	op_tests()
{
	t_dlist *a, *b;
	t_testcase t[SZ];
	t[0] = (t_testcase){{1, 2, 3}, 3, {4, 5, 6, 7}, 4, {PB}, 1, {2, 3}, 2, {1, 4, 5, 6, 7}, 5};
	t[1] = (t_testcase){{1}, 1, {4, 5, 6, 7}, 4, {PB}, 1, {}, 0, {1, 4, 5, 6, 7}, 5};
	t[2] = (t_testcase){{}, 0, {4, 5, 6, 7}, 4, {PB}, 1, {}, 0, {4, 5, 6, 7}, 4};
	t[3] = (t_testcase){{1}, 1, {7}, 1, {PB}, 1, {}, 0, {1, 7}, 2};
	t[4] = (t_testcase){{1}, 1, {}, 0, {PB}, 1, {}, 0, {1}, 1};
	t[5] = (t_testcase){{}, 0, {1}, 1, {PB}, 1, {}, 0, {1}, 1};
	t[6] = (t_testcase){{}, 0, {}, 0, {PB}, 1, {}, 0, {}, 0};
	t[7] = (t_testcase){{4, 5, 6, 7}, 4, {1, 2, 3}, 3, {PA}, 1, {1, 4, 5, 6, 7}, 5, {2, 3}, 2};
	t[8] = (t_testcase){{4, 5, 6, 7}, 4, {1}, 1, {PA}, 1, {1, 4, 5, 6, 7}, 5, {}, 0};
	t[9] = (t_testcase){{4, 5, 6, 7}, 4, {}, 0, {PA}, 1, {4, 5, 6, 7}, 4, {}, 0};
	t[10] = (t_testcase){{7}, 1, {1}, 1, {PA}, 1, {1, 7}, 2, {}, 0};
	t[11] = (t_testcase){{1}, 1, {}, 0, {PA}, 1, {1}, 1, {}, 0};
	t[12] = (t_testcase){{}, 0, {1}, 1, {PA}, 1, {1}, 1, {}, 0};
	t[13] = (t_testcase){{}, 0, {}, 0, {PA}, 1, {}, 0, {}, 0};
	t[14] = (t_testcase){{1, 2, 3}, 3, {4, 5, 6, 7}, 4, {RA}, 1, {2, 3, 1}, 3, {4, 5, 6, 7}, 4};
	t[15] = (t_testcase){{1}, 1, {4, 5, 6, 7}, 4, {RA}, 1, {1}, 1, {4, 5, 6, 7}, 4};
	t[16] = (t_testcase){{}, 0, {4, 5, 6, 7}, 4, {RA}, 1, {}, 0, {4, 5, 6, 7}, 4};
	t[17] = (t_testcase){{4, 5, 6, 7}, 4, {1, 2, 3}, 3, {RB}, 1, {4, 5, 6, 7}, 4, {2, 3, 1}, 3};
	t[18] = (t_testcase){{4, 5, 6, 7}, 4, {1}, 1, {RB}, 1, {4, 5, 6, 7}, 4, {1}, 1};
	t[19] = (t_testcase){{4, 5, 6, 7}, 4, {}, 0, {RB}, 1, {4, 5, 6, 7}, 4, {}, 0};
	t[20] = (t_testcase){{4, 5, 6, 7}, 4, {1, 2, 3}, 3, {RR}, 1, {5, 6, 7, 4}, 4, {2, 3, 1}, 3};
	t[21] = (t_testcase){{4, 5, 6, 7}, 4, {1}, 1, {RR}, 1, {5, 6, 7, 4}, 4, {1}, 1};
	t[22] = (t_testcase){{4, 5, 6, 7}, 4, {}, 0, {RR}, 1, {5, 6, 7, 4}, 4, {}, 0};
	t[23] = (t_testcase){{1}, 1, {4, 5, 6, 7}, 4, {RR}, 1, {1}, 1, {5, 6, 7, 4}, 4};
	t[24] = (t_testcase){{}, 0, {4, 5, 6, 7}, 4, {RR}, 1, {}, 0, {5, 6, 7, 4}, 4};
	t[25] = (t_testcase){{}, 0, {}, 0, {RR}, 1, {}, 0, {}, 0};
	t[26] = (t_testcase){{2, 3, 1}, 3, {4, 5, 6, 7}, 4, {RRA}, 1, {1, 2, 3}, 3, {4, 5, 6, 7}, 4};
	t[27] = (t_testcase){{1}, 1, {4, 5, 6, 7}, 4, {RRA}, 1, {1}, 1, {4, 5, 6, 7}, 4};
	t[28] = (t_testcase){{}, 0, {4, 5, 6, 7}, 4, {RRA}, 1, {}, 0, {4, 5, 6, 7}, 4};
	t[29] = (t_testcase){{4, 5, 6, 7}, 4, {2, 3, 1}, 3, {RRB}, 1, {4, 5, 6, 7}, 4, {1, 2, 3}, 3};
	t[30] = (t_testcase){{4, 5, 6, 7}, 4, {1}, 1, {RRB}, 1, {4, 5, 6, 7}, 4, {1}, 1};
	t[31] = (t_testcase){{4, 5, 6, 7}, 4, {}, 0, {RRB}, 1, {4, 5, 6, 7}, 4, {}, 0};
	t[32] = (t_testcase){{5, 6, 7, 4}, 4, {2, 3, 1}, 3, {RRR}, 1, {4, 5, 6, 7}, 4, {1, 2, 3}, 3};
	t[33] = (t_testcase){{5, 6, 7, 4}, 4, {1}, 1, {RRR}, 1, {4, 5, 6, 7}, 4, {1}, 1};
	t[34] = (t_testcase){{5, 6, 7, 4}, 4, {}, 0, {RRR}, 1, {4, 5, 6, 7}, 4, {}, 0};
	t[35] = (t_testcase){{1}, 1, {5, 6, 7, 4}, 4, {RRR}, 1, {1}, 1, {4, 5, 6, 7}, 4};
	t[36] = (t_testcase){{}, 0, {5, 6, 7, 4}, 4, {RRR}, 1, {}, 0, {4, 5, 6, 7}, 4};
	t[37] = (t_testcase){{}, 0, {}, 0, {RRR}, 1, {}, 0, {}, 0};
	t[38] = (t_testcase){{1, 2, 3}, 3, {4, 5, 6, 7}, 4, {SA}, 1, {2, 1, 3}, 3, {4, 5, 6, 7}, 4};
	t[39] = (t_testcase){{1}, 1, {4, 5, 6, 7}, 4, {SA}, 1, {1}, 1, {4, 5, 6, 7}, 4};
	t[40] = (t_testcase){{}, 0, {4, 5, 6, 7}, 4, {SA}, 1, {}, 0, {4, 5, 6, 7}, 4};
	t[41] = (t_testcase){{4, 5, 6, 7}, 4, {1, 2, 3}, 3, {SB}, 1, {4, 5, 6, 7}, 4, {2, 1, 3}, 3};
	t[42] = (t_testcase){{4, 5, 6, 7}, 4, {1}, 1, {SB}, 1, {4, 5, 6, 7}, 4, {1}, 1};
	t[43] = (t_testcase){{4, 5, 6, 7}, 4, {}, 0, {SB}, 1, {4, 5, 6, 7}, 4, {}, 0};
	t[44] = (t_testcase){{4, 5, 6, 7}, 4, {1, 2, 3}, 3, {SS}, 1, {5, 4, 6, 7}, 4, {2, 1, 3}, 3};
	t[45] = (t_testcase){{4, 5, 6, 7}, 4, {1}, 1, {SS}, 1, {5, 4, 6, 7}, 4, {1}, 1};
	t[46] = (t_testcase){{4, 5, 6, 7}, 4, {}, 0, {SS}, 1, {5, 4, 6, 7}, 4, {}, 0};
	t[47] = (t_testcase){{1}, 1, {4, 5, 6, 7}, 4, {SS}, 1, {1}, 1, {5, 4, 6, 7}, 4};
	t[48] = (t_testcase){{}, 0, {4, 5, 6, 7}, 4, {SS}, 1, {}, 0, {5, 4, 6, 7}, 4};
	t[49] = (t_testcase){{1}, 1, {4}, 1, {SS}, 1, {1}, 1, {4}, 1};
	t[50] = (t_testcase){{}, 0, {}, 0, {SS}, 1, {}, 0, {}, 0};
	t[51] = (t_testcase){{1, 2}, 2, {}, 0, {PB}, 1, {2}, 1, {1}, 1};
	t[52] = (t_testcase){{}, 0, {1, 2}, 2, {PA}, 1, {1}, 1, {2}, 1};
	t[53] = (t_testcase){{1, 2}, 2, {}, 0, {PB, PB}, 2, {}, 0, {2, 1}, 2};
	t[54] = (t_testcase){{}, 0, {1, 2}, 2, {PA, PA}, 2, {2, 1}, 2, {}, 0};
	printf("Starting %d dlist-operational tests.\n", SZ - START);
	for (int i = START; i < SZ; i ++)
	{
		if ((CUR_DEBUG & OP_TEST_BORDER) > 0)
			printf("\n################################################################\n\n");
		if ((CUR_DEBUG & OP_TEST_NUMBERS) > 0)
			printf("test #%i\n", i);
		a = ft_dlist_generate_int(t[i].a, t[i].asz, 0);
		b = ft_dlist_generate_int(t[i].b, t[i].bsz, 0);
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0)
		{
			printf("ORIGINAL:\n");
			assert(print(a, b, iprinter) == 0);
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
		t_dlist *expa = ft_dlist_generate_int(t[i].expa, t[i].expasz, 0);
		t_dlist *expb = ft_dlist_generate_int(t[i].expb, t[i].expbsz, 0);
		int expsza = ft_dlist_size(expa);
		int expszb = ft_dlist_size(expb);
		if ((CUR_DEBUG & OP_TEST_DETAILS) > 0)
			printf("a: %i nodes (expected %i), b: %i nodes (expected %i)\n", nsza, expsza, nszb, expszb);
		int wronga = ft_dlist_ncmp_i(a, expa, expsza + 1) != 0;
		int wrongb = ft_dlist_ncmp_i(b, expb, expszb + 1) != 0;
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0 && (wronga || wrongb || (CUR_DEBUG & OP_TEST_FULLDETAILS_SUCCESS) > 0))
		{
			printf("EXPECTED:\n");
			assert(print(expa, expb, iprinter) == 0);
			printf("ACTUAL:\n");
			assert(print(a, b, iprinter) == 0);
		}
		assert(!wronga && !wrongb);
		ft_dlist_clear(&a, 0, 0);
		ft_dlist_clear(&b, 0, 0);
		ft_dlist_clear(&expa, 0, 0);
		ft_dlist_clear(&expb, 0, 0);
	}
	printf("SUCCESS: all operations performed as predicted\n");
}
