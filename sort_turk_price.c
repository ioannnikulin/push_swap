/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/10 16:00:22 by inikulin         ###   ########.fr       */
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
	to->direct_total = INT_MAX;
	to->rev_total = INT_MAX;
}

static void	rots_copy(t_turk_rots from, t_turk_rots *to)
{
	to->obj = from.obj;
	to->ras = from.ras;
	to->rbs = from.rbs;
	to->rras = from.rras;
	to->rrbs = from.rrbs;
	to->rrs = from.rrs;
	to->rrrs = from.rrrs;
	to->direct_total = from.direct_total;
	to->rev_total = from.rev_total;
}

static void	calc_rbs(t_turk_params *p, t_dlist *obj, t_turk_rots *rs)
{
	t_dlist *justunder;
	int		juncmp;
	int		jabcmp;
	int		junjubcmp;

	justunder = *(p->b);
	while (1)
	{
		juncmp = ft_voidptr_strcmp(obj->content, justunder->content);
		jabcmp = ft_voidptr_strcmp(justunder->prev->content, obj->content);
		junjabcmp = ft_voidptr_strcmp(justunder->content, justunder->prev->content);
		if (juncmp > 0 && (jabcmp < 0 || jabcmp > 0 && junjabcmp > 0)) // 5 > 4 3 2
			return ;
		if (juncmp < 0 || (jabcmp > 0 && junjabcmp < 0)) // 1 > 3 4 or 5 > 2 3 4
		{
			justunder = justunder->next;
			rs->rbs ++;
			continue;
		} // TODO: make fucking tests for all cases, this is incomprehensible
	}
}

static void	calc_price(t_turk_params *p, int c, t_turk_rots *rs)
{
	rs->ras = c;
	rs->rras = p->asz - rs->ras;
	rs->rrbs = p->bsz - rs->rbs;
	rs->rrs = *ft_min_int(&(rs->ras), &(rs->rbs));
	rs->ras -= rs->rrs;
	rs->rbs -= rs->rrs;
	rs->rrrs = *ft_min_int(&(rs->rras), &(rs->rrbs));
	rs->rras -= rs->rrrs;
	rs->rrbs -= rs->rrrs;
	direct_total = rs->ras + rs->rbs + rs->rrs;
	rev_total = rs->rras + rs->rrbs + rs->rrrs;
}

t_turk_rots	find_cheapest(t_turk_params *p)
{
	t_dlist 	*d;
	int			c;
	t_turk_rots	cur;
	t_turk_rots	best;

	d = p->a;
	c = 0;
	rots_init(best, 0);
	while (c < p->asz)
	{
		rots_init(cur, d);
		calc_rbs(p, &cur);
		calc_price(p, c, &cur);
		if (*ft_min_int(&(cur->direct_total), &(cur->rev_total)) < \
			*ft_min_int(&(best->direct_total), &(best->rev_total)))
			rots_copy(cur, best);
		d = d->next;
		c ++;
	}
	return (best);
}
