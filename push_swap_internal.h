/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:01:39 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 19:30:21 by inikulin         ###   ########.fr       */
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
# define MAX_DEBUG 1023

void	print(t_dlist *a, t_dlist *b, int debug_lvl);
void	op_s(t_dlist **a, int debug_lvl);
void	op_ss(t_dlist **a, t_dlist **b, int debug_lvl);
#endif
