/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 17:54:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

void	rots_init(t_turk_rots *to, t_dlist *d, int c);
void	rots_copy(t_turk_rots from, t_turk_rots *to);
t_turk_rots	ff(t_turk_params *p, t_turk_rots base);
t_turk_rots	fb(t_turk_params *p, t_turk_rots base);
t_turk_rots	bf(t_turk_params *p, t_turk_rots base);
t_turk_rots	bb(t_turk_params *p, t_turk_rots base);
void	calc_rbs(t_turk_params *p, t_turk_rots *rs, int toa);

static void	calc_price(t_turk_params *p, t_turk_rots *rs, int c, int toa)
{
	t_turk_rots	best;
	t_turk_rots	cand;

	if (toa == 1)
		toa = -1;
	else
		toa = 1;
	calc_rbs(p, rs, toa);
	if (c >= 0)
		rs->ras = c;
	else
		rs->rras = -c;
	rots_init(&best, rs->obj, c);
	best = ff(p, *rs);
	cand = fb(p, *rs);
	if (cand.total < best.total)
		best = cand;
	cand = bf(p, *rs);
	if (cand.total < best.total)
		best = cand;
	cand = bb(p, *rs);
	if (cand.total < best.total)
		best = cand;
	rots_copy(best, rs);
}

static void	direction_hack(t_turk_params *p, int toa, int mode, t_turk_rots *best)
{
	t_dlist	**t;

	if (!toa)
		return ;
	t = p->a;
	p->a = p->b;
	p->b = t;
	ft_swap_i(&(p->asz), &(p->bsz));
	if (mode == 2)
	{
		ft_swap_i(&(best->ras), &(best->rbs));
		ft_swap_i(&(best->rras), &(best->rrbs));
	}
}

static void	try_node(t_turk_params *p, t_turk_rots *d, t_turk_rots *best, int toa)
{
	if (!toa && (d->obj->flags & LEAVE_IN_A) != 0)
		return ;
	calc_price(p, d, d->offset, toa);
	if (!best->obj || d->total < best->total)
		rots_copy(*d, best);
	if ((CUR_DEBUG & TURK_EACH_NODE_PRICES) > 0)
		ft_printf("best option for sending node #%i would take %i operations\n", d->offset, d->total);
}

t_turk_rots	find_cheapest(t_turk_params *p, int toa)
{
	t_turk_rots	fw;
	t_turk_rots	bk;
	t_turk_rots	best;

	direction_hack(p, toa, 1, 0);
	rots_init(&fw, *(p->a), 0);
	rots_init(&bk, (*(p->a))->prev, -1);
	rots_init(&best, 0, 0);
	while (fw.offset < p->asz && fw.offset < best.total - 1)
	{
		try_node(p, &fw, &best, toa);
		rots_init(&fw, fw.obj->next, fw.offset + 1);
	}
	while (-bk.offset < p->asz && -bk.offset < best.total - 1)
	{
		try_node(p, &bk, &best, toa);
		rots_init(&bk, bk.obj->prev, bk.offset - 1);
	}
	// TODO: possible error if none are eligible for sending (all marked to be in lis)
	direction_hack(p, toa, 2, &best);
	return (best);
}
