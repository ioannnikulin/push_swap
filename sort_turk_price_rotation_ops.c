/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price_rotation_ops.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/03 13:22:41 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

void	rots_init(t_turk_rots *to, t_dlist *d)
{
	to->obj = d;
	to->ras = 0;
	to->rbs = 0;
	to->rras = 0;
	to->rrbs = 0;
	to->rrs = 0;
	to->rrrs = 0;
	to->total = INT_MAX;
}

void	rots_copy(t_turk_rots from, t_turk_rots *to)
{
	to->obj = from.obj;
	to->ras = from.ras;
	to->rbs = from.rbs;
	to->rrs = from.rrs;
	to->rras = from.rras;
	to->rrbs = from.rrbs;
	to->rrrs = from.rrrs;
	to->total = from.total;
}
