/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/17 21:03:34 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

static void	rots_init(t_turk_rots *to, t_dlist *d)
{
	to->obj = d;
	to->ras = INT_MAX;
	to->rbs = INT_MAX;
	to->rras = INT_MAX;
	to->rrbs = INT_MAX;
	to->rrs = INT_MAX;
	to->rrrs = INT_MAX;
	to->total = INT_MAX;
}

static void	rots_copy(t_turk_rots from, t_turk_rots *to)
{
	to->ras = from.ras;
	to->rbs = from.rbs;
	to->rrs = from.rrs;
	to->rras = from.rras;
	to->rrbs = from.rrbs;
	to->rrrs = from.rrrs;
	to->total = from.total;
}

static void	calc_rbs(t_turk_params *p, t_turk_rots *rs)
{
	t_dlist *justunder;
	int		juncmp;
	int		jabcmp;
	int		junjabcmp;

	justunder = *(p->b);
	rs->rbs = 0;
	while (1)
	{
		juncmp = ft_voidptr_icmp(rs->obj->content, justunder->content);
		jabcmp = ft_voidptr_icmp(justunder->prev->content, rs->obj->content);
		junjabcmp = ft_voidptr_icmp(justunder->content, justunder->prev->content);
		if (juncmp < 0 && jabcmp > 0 && junjabcmp > 0)
			return ;
		if (juncmp > 0 && jabcmp < 0 && junjabcmp > 0)
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
	base.total = base.ras + base.rbs + base.rrs;
	return (base);
}

static t_turk_rots	fb(t_turk_params *p, t_turk_rots base)
{
	base.rrbs = p->bsz - base.rbs - (p->bsz == 1);
	base.rbs = 0;
	base.total = base.ras + base.rrbs;
	return (base);
}

static t_turk_rots	bf(t_turk_params *p, t_turk_rots base)
{
	base.rras = p->asz - base.ras - (p->asz == 1);
	base.ras = 0;
	base.total = base.rbs + base.rras;
	return (base);
}

static t_turk_rots	bb(t_turk_params *p, t_turk_rots base)
{
	base.rras = p->asz - base.ras - (p->asz == 1);
	base.rrbs = p->bsz - base.rbs - (p->bsz == 1);
	base.rrrs = *ft_min_int(&(base.rras), &(base.rrbs));
	base.rras -= base.rrrs;
	base.rrbs -= base.rrrs;
	base.total = base.rras + base.rrbs + base.rrrs;
	return (base);
}
static void	calc_price(t_turk_params *p, int c, t_turk_rots *rs)
{
	rs->ras = c;
	rs->rras = p->asz - rs->ras - (p->asz == 1);
	rs->rrs = *ft_min_int(&(rs->ras), &(rs->rbs));
	rs->ras -= rs->rrs;
	rs->rbs -= rs->rrs;
	rs->rrrs = *ft_min_int(&(rs->rras), &(rs->rrbs));
	rs->rras -= rs->rrrs;
	rs->rrbs -= rs->rrrs;
	rs->direct_total = rs->ras + rs->rbs + rs->rrs;
	rs->rev_total = rs->rras + rs->rrbs + rs->rrrs;
}

t_turk_rots	find_cheapest(t_turk_params *p)
{
	t_dlist 	*d;
	int			c;
	t_turk_rots	cur;
	t_turk_rots	best;

	d = *(p->a);
	c = 0;
	rots_init(&best, 0);
	while (c < p->asz && c < best.total)
	{
		rots_init(&cur, d);
		calc_rbs(p, &cur);
		calc_price(p, c, &cur);
		if (cur.total < best.total)
			rots_copy(cur, &best);
		d = d->next;
		c ++;
	}
	return (best);
}
