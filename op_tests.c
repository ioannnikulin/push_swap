/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/01/27 15:08:37 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "push_swap_internal.h"
#define START 0
#define SZ 1

typedef enum eOP {
	PA, PB, SA, SB, SS, RA, RB, RR, RRA, RRB, RRR
}	OP;

typedef struct s_testcase {
	char	*a[10];
	char	*b[10];
	OP	ops[10];
	int opsz;
	char	*expa[10];
	char	*expb[10];
}	t_testcase;

void	op_tests(int debug_lvl)
{
	t_dlist *a, *b;
	t_testcase t[SZ];
	t[0] = (t_testcase){{"1", "2", "3", NULL}, {"4", "5", "6", "7", NULL}, {PB}, 1, {"2", "3", NULL}, {"3", "4", "5", "6", "7", NULL}};
	printf("Starting %d dlist-operational tests.\n", SZ);
	for (int i = START; i < SZ; i ++)
	{
		if ((debug_lvl & OP_TEST_NUMBERS) > 0)
			printf("%i\n", i);
		a = ft_dlist_generate(t[i].a, 0);
		b = ft_dlist_generate(t[i].b, 0);
		if ((debug_lvl & OP_TEST_FULLDETAILS) > 0)
		{
			printf("ORIGINAL:\n");
			print(a, b, debug_lvl);
		}
		int op = t[i].opsz;
		while (op --)
		{
			switch (t[i].ops[op])
			{
				case PA:
					op_pa(&a, &b, debug_lvl);
					break;
				case PB:
					op_pb(&a, &b, debug_lvl);
					break;
				case RA:
					op_ra(&a, debug_lvl);
					break;
				case RB:
					op_rb(&b, debug_lvl);
					break;
				case RR:
					op_rr(&a, &b, debug_lvl);
					break;
				case SA:
					op_sa(&a, debug_lvl);
					break;
				case SB:
					op_sb(&b, debug_lvl);
					break;
				case SS:
					op_ss(&a, &b, debug_lvl);
					break;
				case RRA:
					op_rra(&a, debug_lvl);
					break;
				case RRB:
					op_rrb(&b, debug_lvl);
					break;
				case RRR:
					op_rrr(&a, &b, debug_lvl);
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
		if ((debug_lvl & OP_TEST_DETAILS) > 0)
			printf("a: %i nodes (expected %i), b: %i nodes (expected %i)\n", nsza, expsza, nszb, expszb);
		if ((debug_lvl & OP_TEST_FULLDETAILS) > 0 && (nsza != expsza || nszb != expszb))
		{
			printf("EXPECTED:\n");
			print(expa, expb, debug_lvl);
		}
		if ((debug_lvl & OP_TEST_FULLDETAILS) > 0 && (nsza != expsza || nszb != expszb))
		{
			printf("ACTUAL:\n");
			print(a, b, debug_lvl);
		}
		assert(nsza == expsza && nszb == expszb);
		if ((debug_lvl & OP_TEST_DETAILS) > 0)
			printf("comparing a: ");
		assert(ft_dlist_ncmp_str(a, expa, expsza + 1) == 0);
		if ((debug_lvl & OP_TEST_DETAILS) > 0)
			printf("ok\ncomparing b: ");
		assert(ft_dlist_ncmp_str(b, expb, expszb + 1) == 0);
		if ((debug_lvl & OP_TEST_DETAILS) > 0)
			printf("ok\n");
	}
	printf("SUCCESS: all operations performed as predicted\n");
}
