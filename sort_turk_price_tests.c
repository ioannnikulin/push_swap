/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price_tests.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/02/10 18:54:41 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include "sort_turk_internal.h"
#define START 0
#define SZ 1 

typedef struct s_testcase {
	int	a;
	int	*b;
	int	bsz;
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
		printf("direct: %i %i\n", exp.direct_total, act.direct_total);
		printf("rev: %i %i\n", exp.rev_total, act.rev_total);
	}
	assert(exp.ras == act.ras);
	assert(exp.rbs == act.rbs);
	assert(exp.rrs == act.rrs);
	assert(exp.rras == act.rras);
	assert(exp.rrbs == act.rrbs);
	assert(exp.rrrs == act.rrrs);
	assert(exp.direct_total == act.direct_total);
	assert(exp.rev_total == act.rev_total);
}

static void nothing(void *c)
{
	(void)c;
}

t_turk_rots	find_cheapest(t_turk_params *p);

void	sort_turk_price_tests()
{
	t_dlist *a, *b;
	t_testcase t[SZ];
	t[0] = (t_testcase){1, (int[]){5, 4, 3, 2}, 4, (t_turk_rots){0, 0, 0, 0, 0, 0, 0, 0, 0}};
	printf("Starting %d TurkSort price-estimation tests.\n", SZ - START);
	for (int i = START; i < SZ; i ++)
	{
		if ((CUR_DEBUG & OP_TEST_BORDER) > 0)
			printf("\n################################################################\n\n");
		if ((CUR_DEBUG & OP_TEST_NUMBERS) > 0)
			printf("test #%i\n", i);
		a = ft_dlist_generate_int((int[]){t[i].a}, 1, 0);
		b = ft_dlist_generate_int(t[i].b, t[i].bsz, 0);
		t_turk_rots act = find_cheapest(&(t_turk_params){&a, &b, 1, t[i].bsz});
		if ((CUR_DEBUG & OP_TEST_FULLDETAILS) > 0)
		{
			printf("ORIGINAL:\n");
			assert(print(a, b, iprinter) == 0);
			printf("PRICES EXP / ACTUAL:\n");
			printprices(t[i].exp, act, 1);
		}
		else
			printprices(t[i].exp, act, 0);
		ft_dlist_clear(&a, nothing, 0);
		ft_dlist_clear(&b, nothing, 0);
	}
	printf("SUCCESS: all operations performed as predicted\n");
}
