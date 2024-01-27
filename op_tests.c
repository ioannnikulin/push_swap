/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin  yb        #+#    #+#             */
/*   Updated: 2024/01/26 19:19:36 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
//#define DEBUG
#define START 0
#define SZ 1

typedef struct s_testcase {
	char	*a[10];
	int sza;
	char	*b[10];
	int szb;
	OP	ops[10];
	int opsz;
	char	*resa[10];
	int rsza;
	char	*resb[10];
	int rszb;
}	t_testcase;

enum OP {
	PA, PB, SA, SB, SS, RA, RB, RR, RRA, RRB, RRR
};

void	errors(void)
{
	t_dlist *a, *b;
	int op;
	t_testcase t[SZ];
	t[0] = (t_testcase){{"1", "2", "3"}, 3, {"4", "5", "6", "7"}, 4, {PB}, 1, {"2", "3"}, 2, {"3", "4", "5", "6", "7"}, 5};
	printf("Starting %d tests.\n", SZ);
	for (int i = START; i < SZ; i ++)
	{
#ifdef DEBUG
		printf("%i\n", i);
#endif
		a = ft_dlist_generate(t[i].a, 0);
		b = ft_dlist_generate(t[i].b, 0);
		op = t[i].opsz;
		while (op --)
		{

		}
#ifdef DEBUG
		printf("%i %lu\n", rd, strlen(err));
#endif
		assert(rd == (int)strlen(err));
		assert(strncmp(rdbuf, err, rd) == 0);
		close(fs);
	}
	remove("stdout.txt");
	remove("stderr.txt");
	printf("SUCCESS: the program failed on all erroneous input\n");
}

#include "push_swap_internal.h"
#define CUR_DEBUG MAX_DEBUG

void 

int	main(void)
{
	errors();
	return (0);
}
