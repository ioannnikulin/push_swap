/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_price_rotation_strategies.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 21:30:59 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

void	calc_rbs(t_turk_params *p, t_turk_rots *rs, int toa)
{
	t_dlist	*justunder;
	int		juncmp;
	int		jabcmp;
	int		junjabcmp;

	justunder = *(p->b);
	rs->rbs = 0;
	while (1)
	{
		juncmp = toa * ft_voidptr_icmp(rs->obj->content, justunder->content);
		jabcmp = toa * ft_voidptr_icmp(justunder->prev->content,
				rs->obj->content);
		junjabcmp = toa * ft_voidptr_icmp(justunder->content,
				justunder->prev->content);
		if (junjabcmp > 0 && (juncmp > 0 || jabcmp > 0))
			return ;
		if (juncmp > 0 && jabcmp > 0 && junjabcmp < 0)
			return ;
		justunder = justunder->next;
		rs->rbs ++;
	}
}

t_turk_rots	ff(t_turk_params *p, t_turk_rots base)
{
	base.rrs = *ft_min_int(&(base.ras), &(base.rbs));
	base.ras -= base.rrs;
	base.rbs -= base.rrs;
	(void)p;
	base.total = base.ras + base.rbs + base.rrs + 1;
	if ((CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0)
		ft_printf("FF strategy: %i operations\n", base.total);
	return (base);
}

t_turk_rots	fb(t_turk_params *p, t_turk_rots base)
{
	base.rrbs = p->bsz - base.rbs - (p->bsz == 1);
	base.rbs = 0;
	base.total = base.ras + base.rrbs + 1;
	if ((CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0)
		ft_printf("FB strategy: %i operations\n", base.total);
	return (base);
}

t_turk_rots	bf(t_turk_params *p, t_turk_rots base)
{
	base.rras = p->asz - base.ras - (p->asz == 1);
	base.ras = 0;
	base.total = base.rbs + base.rras + 1;
	if ((CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0)
		ft_printf("BF strategy: %i operations\n", base.total);
	return (base);
}

t_turk_rots	bb(t_turk_params *p, t_turk_rots base)
{
	base.rras = p->asz - base.ras - (p->asz == 1);
	base.rrbs = p->bsz - base.rbs - (p->bsz == 1);
	base.ras = 0;
	base.rbs = 0;
	base.rrrs = *ft_min_int(&(base.rras), &(base.rrbs));
	base.rras -= base.rrrs;
	base.rrbs -= base.rrrs;
	base.total = base.rras + base.rrbs + base.rrrs + 1;
	if ((CUR_DEBUG & TURK_ALL_DIRECTION_PRICES) > 0)
		ft_printf("BB strategy: %i operations\n", base.total);
	return (base);
}
