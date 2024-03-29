/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:01:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/24 16:05:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INTERNAL_H
# define PUSH_SWAP_INTERNAL_H
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
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
# define STAGE_RESULT_PRINT 262144
# define OPS_COUNT_TOTAL 524288
# define LIS_DEBUG 2097152
# define FIXED_WIDTH 4194304
# define MAX_DEBUG 8388607
# define MANUAL_OPS 432
# define SUBMISSION 21504
//# define TURK_DEBUG (OP_NAME | BORDER_PRINTOUT | OP_TEST_FULLDETAILS | 
//STAGE_RESULT_PRINT | OPS_COUNT_TOTAL | STACK_HEADER_FOOTER | FIXED_WIDTH 
//| LIS_DEBUG)
# if CHECKER == 1
#  define CUR_DEBUG 0
# else
#  define CUR_DEBUG SUBMISSION
# endif

# define LEAVE_IN_A 1

typedef enum e_OP
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_OP;

int		sort(t_dlist **a, t_dlist **b);
int		sorted(t_dlist *root);
int		print(t_dlist *a, t_dlist *b, void (*p)(void *, int));
void	sprinter(void *content, int flags);
void	iprinter(void *content, int flags);
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
void	apply(t_dlist **a, t_dlist **b, t_OP op);
int		error(int ret, t_dlist **a, t_dlist **b);
#endif
