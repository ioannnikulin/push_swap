/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:27:18 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 14:43:23 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "push_swap_internal.h"
#define START 0
#define SZ 11

void	errors(int cur_debug)
{
	int		fs, rd;
	char	rdbuf[30];
	char	callbuf[127];
	char args[SZ][30] = {
		"1 2 2147483648 3 4"
		, "1 2 -2147483649 3 4"
		, ""
		, "1 2 3 1 4"
		, "1 2 i 3 4"
		, "1 2 *3 4"
		, "1 2 1+1 4"
		, "--"
		, "1 +"
		, "1 \"2 3 4\" 3"
		, "1 \"2 3 4\" --1"
	};
	char err[] = "Error\n";
	printf("Starting %d erroneous tests.\n", SZ);
	for (int i = START; i < SZ; i ++)
	{
		if ((cur_debug & OP_TEST_NUMBERS) > 0)
			printf("%i\n", i);
		remove("stdout.txt");
		remove("stderr.txt");
		bzero(callbuf, 127);
		strcat(strcat(strcat(callbuf, "./push_swap "), args[i]), " > stdout.txt 2> stderr.txt");
		system(callbuf);
		fs = open("stdout.txt", O_RDONLY, 0600);
		assert(fs && read(fs, &rdbuf, 30) == 0);
		close(fs);
		fs = open("stderr.txt", O_RDONLY, 0600);
		assert(fs);
		rd = read(fs, &rdbuf, 30);
		if ((cur_debug & OP_TEST_DETAILS) > 0)
			printf("%i %lu\n", rd, strlen(err));
		assert(rd == (int)strlen(err));
		assert(strncmp(rdbuf, err, rd) == 0);
		close(fs);
	}
	remove("stdout.txt");
	remove("stderr.txt");
	printf("SUCCESS: the program failed on all erroneous input\n");
}
