/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mark_lis_proc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/24 16:03:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

int	lis(t_dlist *obj, t_dlist *end);

static void	loop(t_dlist **best, t_dlist *end, t_dlist *obj)
{
	t_dlist	*cur;
	int		curlis;

	cur = obj->next;
	while (cur != end)
	{
		curlis = lis(cur, end);
		if ((ft_voidptr_icmp(obj->content, cur->content) < 0) && \
			(!(*best) || (curlis >= (*best)->lisl)))
			*best = cur;
		cur = cur->next;
	}
}

int	lis(t_dlist *obj, t_dlist *end)
{
	t_dlist	*best;

	if (obj->lisl != 0)
		return (obj->lisl);
	if (obj->next == end)
	{
		obj->lisl = 1;
		return (1);
	}
	best = 0;
	loop(&best, end, obj);
	if (best)
	{
		obj->lisl = best->lisl + 1;
		obj->lisn = best;
		return (obj->lisl);
	}
	obj->lisl = 1;
	return (obj->lisl);
}
