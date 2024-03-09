/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 19:52:32 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

void	rots_init(t_turk_rots *to, t_dlist *d);
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
	rs->ras = c;
	rots_init(&best, 0);
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

static t_dlist*	direction_hack(t_turk_params *p, int toa, int mode, t_turk_rots *best, int *c)
{
	t_dlist	**t;

	if (toa)
	{
		t = p->a;
		p->a = p->b;
		p->b = t;
		ft_swap_i(&(p->asz), &(p->bsz));
	}
	if (mode == 1)
		rots_init(best, 0);
	if (mode == 2 && toa)
	{
		ft_swap_i(&(best->ras), &(best->rbs));
		ft_swap_i(&(best->rras), &(best->rrbs));
	}
	if (c)
		*c = 0;
	return (*(p->a));
}

t_turk_rots	find_cheapest(t_turk_params *p, int toa)
{
	t_dlist 	*d;
	int			c;
	t_turk_rots	cur;
	t_turk_rots	best;
	int			rc;

	d = direction_hack(p, toa, 1, &best, &c);
	while (c < p->asz)
	{
		rc = p->asz - c - (p->asz == 1);
		if ((toa || (d->flags & LEAVE_IN_A) == 0) && (*ft_min_int(&c, &rc) < best.total - 1))
		{
			rots_init(&cur, d);
			calc_price(p, &cur, c, toa);
			if (cur.total < best.total)
				rots_copy(cur, &best);
			if ((CUR_DEBUG & TURK_EACH_NODE_PRICES) > 0)
				ft_printf("best option for sending node #%i would take %i operations\n", c, cur.total);
		}
		d = d->next;
		c ++;
	}
	// TODO: possible error if none are eligible for sending (all marked to be in lis)
	direction_hack(p, toa, 2, &best, 0);
	return (best);
}
