/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/24 16:03:56 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

void		rots_init(t_turk_rots *to, t_dlist *d);
void		rots_copy(t_turk_rots from, t_turk_rots *to);
t_turk_rots	ff(t_turk_params *p, t_turk_rots base);
t_turk_rots	fb(t_turk_params *p, t_turk_rots base);
t_turk_rots	bf(t_turk_params *p, t_turk_rots base);
t_turk_rots	bb(t_turk_params *p, t_turk_rots base);
void		calc_rbs(t_turk_params *p, t_turk_rots *rs, int toa);

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

typedef struct s_hack_params
{
	t_turk_params	*p;
	int				toa;
	int				mode;
	t_turk_rots		*best;
	int				*c;
}	t_hack_params;

static t_dlist	*direction_hack(t_hack_params *h)
{
	t_dlist	**t;

	if (h->toa)
	{
		t = h->p->a;
		h->p->a = h->p->b;
		h->p->b = t;
		ft_swap_i(&(h->p->asz), &(h->p->bsz));
	}
	if (h->mode == 1)
		rots_init(h->best, 0);
	if (h->mode == 2 && h->toa)
	{
		ft_swap_i(&(h->best->ras), &(h->best->rbs));
		ft_swap_i(&(h->best->rras), &(h->best->rrbs));
	}
	if (h->c)
		*(h->c) = 0;
	return (*(h->p->a));
}

t_turk_rots	find_cheapest(t_turk_params *p, int toa)
{
	t_dlist		*d;
	int			c;
	t_turk_rots	cur;
	t_turk_rots	best;
	int			rc;

	d = direction_hack(&(t_hack_params){p, toa, 1, &best, &c});
	while (c < p->asz)
	{
		rc = p->asz - c - (p->asz == 1);
		if ((toa || (d->flags & LEAVE_IN_A) == 0) && \
			(*ft_min_int(&c, &rc) < best.total - 1))
		{
			rots_init(&cur, d);
			calc_price(p, &cur, c, toa);
			if (cur.total < best.total)
				rots_copy(cur, &best);
			if ((CUR_DEBUG & TURK_EACH_NODE_PRICES) > 0)
				ft_printf("node #%i - best %i operations\n", c, cur.total);
		}
		d = d->next;
		c ++;
	}
	direction_hack(&(t_hack_params){p, toa, 2, &best, 0});
	return (best);
}
