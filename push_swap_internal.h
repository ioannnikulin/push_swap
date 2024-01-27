/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:01:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 19:22:27 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_INTERNAL_H
# define PUSH_SWAP_INTERNAL_H
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"
# define OP_NAME 32
# define STACK_HEADER_FOOTER 128
# define NEWLINE_BETWEEN_ELEMENTS 256
# define BORDER_PRINTOUT 512
# define OP_TEST_NUMBERS 1024
# define OP_TEST_DETAILS 2048
# define OP_TEST_FULLDETAILS 4096
# define OP_TEST_BORDER 8192
# define MAX_DEBUG 16383

int		print(t_dlist *a, t_dlist *b, int debug_lvl, void (*p)(void *));
void	sprinter(void *content);
void	iprinter(void *content);
void	op_sa(t_dlist **a, int debug_lvl);
void	op_sb(t_dlist **b, int debug_lvl);
void	op_ss(t_dlist **a, t_dlist **b, int debug_lvl);
void	op_pa(t_dlist **a, t_dlist **b, int debug_lvl);
void	op_pb(t_dlist **a, t_dlist **b, int debug_lvl);
void	op_ra(t_dlist **a, int debug_lvl);
void	op_rb(t_dlist **b, int debug_lvl);
void	op_rr(t_dlist **a, t_dlist **b, int debug_lvl);
void	op_rra(t_dlist **a, int debug_lvl);
void	op_rrb(t_dlist **b, int debug_lvl);
void	op_rrr(t_dlist **a, t_dlist **b, int debug_lvl);
#endif
