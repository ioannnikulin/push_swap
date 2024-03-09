/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mark_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/09 15:52:54 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

static int	lis(t_dlist *obj, t_dlist *end)
{
	t_dlist	*cur;
	t_dlist	*best;
	int		curlis;

	if (obj->lisl != 0)
		return (obj->lisl);
	if (obj->next == end)
	{
		obj->lisl = 1;
		return (1);
	}
	if ((int)(intptr_t)obj->content == 0 && (int)(intptr_t)obj->prev->content == 2)
	{
		int abc = 0;
		abc ++;
	}
	cur = obj->next;
	best = 0;
	while (cur != end)
	{
		curlis = lis(cur, end);
		if ((ft_voidptr_icmp(obj->content, cur->content) < 0) && (!best || (curlis >= best->lisl)))
			best = cur;
		cur = cur->next;
	}
	if (best)
	{
		obj->lisl = best->lisl + 1;
		obj->lisn = best;
		return (obj->lisl);
	}
	obj->lisl = 1;
	return (obj->lisl);
}

static t_dlist*	smallest(t_dlist* cur, t_dlist *end)
{
	t_dlist *res;

	if (!cur->next || cur->next == end)
		return (cur);
	res = smallest(cur->next, end);
	if (ft_voidptr_icmp(cur->content, res->content) < 0)
		res = cur;
	return (res);
}

t_dlist	*mark_lis(t_dlist *a, int asz)
{
	t_dlist	*cur;
	t_dlist	*best;
	int	checked;

	a = smallest(a, a);
	if ((CUR_DEBUG & LIS_DEBUG) > 0)
	{
		ft_printf("smallest element is ");
		iprinter(a->content);
		ft_printf("\n");
	}
	lis(a, a);
	best = a;
	cur = best->next;
	checked = 1;
	while (cur->next != a)
	{
		checked ++;
		if (best->lisl <= cur->lisl)
			best = cur;
		if (best->lisl >= asz - checked)
			break;
		cur = cur->next;
	}
	cur = best;
	while (cur != 0)
	{
		cur->flags = cur->flags | LEAVE_IN_A;
		cur = cur->lisn;
	}
	return (best);
}

