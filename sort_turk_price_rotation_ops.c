/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price_rotation_ops.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 18:03:42 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

void	rots_init(t_turk_rots *to, t_dlist *d, int c)
{
	to->obj = d;
	to->offset = c;
	to->ras = 0;
	if (c > 0)
		to->ras = c;
	to->rbs = 0;
	to->rras = 0;
	if (c < 0)
		to->rras = 1;
	to->rrbs = 0;
	to->rrs = 0;
	to->rrrs = 0;
	to->total = INT_MAX;
}

void	rots_copy(t_turk_rots from, t_turk_rots *to)
{
	to->obj = from.obj;
	to->offset = from.offset;
	to->ras = from.ras;
	to->rbs = from.rbs;
	to->rrs = from.rrs;
	to->rras = from.rras;
	to->rrbs = from.rrbs;
	to->rrrs = from.rrrs;
	to->total = from.total;
}
