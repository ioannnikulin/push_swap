/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:01:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/28 14:26:31 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INTERNAL_H
# define PUSH_SWAP_INTERNAL_H
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"
# define OP_NAME 16384
# define STACK_HEADER_FOOTER 128
# define NEWLINE_BETWEEN_ELEMENTS 256
# define BORDER_PRINTOUT 512
# define OP_TEST_NUMBERS 1024
# define OP_TEST_DETAILS 2048
# define OP_TEST_FULLDETAILS 4096
# define OP_TEST_BORDER 8192
# define OP_TEST_FULLDETAILS_SUCCESS 32768
# define MAX_DEBUG 65535
# define MANUAL_OPS 128 + 16 + 32
# define CUR_DEBUG 32

int		sort(t_dlist **a, t_dlist **b);
int		print(t_dlist *a, t_dlist *b, void (*p)(void *));
void	sprinter(void *content);
void	iprinter(void *content);
void	op_sa(t_dlist **a);
void	op_sb(t_dlist **b);
void	op_ss(t_dlist **a, t_dlist **b);
void	op_pa(t_dlist **a, t_dlist **b);
void	op_pb(t_dlist **a, t_dlist **b);
void	op_ra(t_dlist **a);
void	op_rb(t_dlist **b);
void	op_rr(t_dlist **a, t_dlist **b);
void	op_rra(t_dlist **a);
void	op_rrb(t_dlist **b);
void	op_rrr(t_dlist **a, t_dlist **b);
int		error(int ret, t_dlist **a, t_dlist **b, int *prices);
#endif
