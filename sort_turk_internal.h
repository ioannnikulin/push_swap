/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 21:37:11 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_TURK_INTERNAL_H
# define SORT_TURK_INTERNAL_H
# include "push_swap_internal.h"
# define TURK_EACH_NODE_PRICES 65536
# define TURK_ALL_DIRECTION_PRICES 131072

typedef struct s_turk_params
{
	t_dlist	**a;
	t_dlist	**b;
	int		asz;
	int		bsz;
	t_dlist	*lis_start;
}	t_turk_params;

typedef struct s_turk_rots
{
	t_dlist	*obj;
	int		ras;
	int		rbs;
	int		rrs;
	int		rras;
	int		rrbs;
	int		rrrs;
	int		total;
}	t_turk_rots;

#endif
