/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/02 18:32:20 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

static void	rots_init(t_turk_rots *to, t_dlist *d)
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

static void	rots_copy(t_turk_rots from, t_turk_rots *to)
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

static void	calc_rbs(t_turk_params *p, t_turk_rots *rs, int toa)
{
	t_dlist *justunder;
	int		juncmp;
	int		jabcmp;
	int		junjabcmp;

	justunder = *(p->b);
	rs->rbs = 0;
	while (1)
	{
		juncmp = toa * ft_voidptr_icmp(rs->obj->content, justunder->content);
		jabcmp = toa * ft_voidptr_icmp(justunder->prev->content, rs->obj->content);
		junjabcmp = toa * ft_voidptr_icmp(justunder->content, justunder->prev->content);
		if (junjabcmp > 0 && (juncmp > 0 || jabcmp > 0))
			return ;
		if (juncmp > 0 && jabcmp > 0 && junjabcmp < 0)
			return ;
		justunder = justunder->next;
		rs->rbs ++;
	}
}

static t_turk_rots	ff(t_turk_params *p, t_turk_rots base)
{
	base.rrs = *ft_min_int(&(base.ras), &(base.rbs));
	base.ras -= base.rrs;
	base.rbs -= base.rrs;
	(void)p;
	base.total = base.ras + base.rbs + base.rrs + 1;
	#if (CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0
		ft_printf("FF strategy: %i operations\n", base.total);
	#endif
	return (base);
}

static t_turk_rots	fb(t_turk_params *p, t_turk_rots base)
{
	base.rrbs = p->bsz - base.rbs - (p->bsz == 1);
	base.rbs = 0;
	base.total = base.ras + base.rrbs + 1;
	#if (CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0
		ft_printf("FB strategy: %i operations\n", base.total);
	#endif
	return (base);
}

static t_turk_rots	bf(t_turk_params *p, t_turk_rots base)
{
	base.rras = p->asz - base.ras - (p->asz == 1);
	base.ras = 0;
	base.total = base.rbs + base.rras + 1;
	#if (CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0
		ft_printf("BF strategy: %i operations\n", base.total);
	#endif
	return (base);
}

static t_turk_rots	bb(t_turk_params *p, t_turk_rots base)
{
	base.rras = p->asz - base.ras - (p->asz == 1);
	base.rrbs = p->bsz - base.rbs - (p->bsz == 1);
	base.ras = 0;
	base.rbs = 0;
	base.rrrs = *ft_min_int(&(base.rras), &(base.rrbs));
	base.rras -= base.rrrs;
	base.rrbs -= base.rrrs;
	base.total = base.rras + base.rrbs + base.rrrs + 1;
	#if (CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0
		ft_printf("BB strategy: %i operations\n", base.total);
	#endif
	return (base);
}

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

	d = direction_hack(p, toa, 1, &best, &c);
	while (c < p->asz && c < best.total)
	{
		rots_init(&cur, d);
		calc_price(p, &cur, c, toa);
		if (cur.total < best.total)
			rots_copy(cur, &best);
		#if (CUR_DEBUG & TURK_EACH_NODE_PRICES) > 0
			ft_printf("best option for sending node #%i would take %i operations\n", c, best.total);
		#endif
		d = d->next;
		c ++;
	}
	direction_hack(p, toa, 2, &best, 0);
	return (best);
}
