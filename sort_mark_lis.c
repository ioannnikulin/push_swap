/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mark_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/16 22:25:22 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

int	lis(t_dlist *obj, t_dlist *end);

static t_dlist	*smallest(t_dlist *cur, t_dlist *end)
{
	t_dlist	*res;

	if (!cur->next || cur->next == end)
		return (cur);
	res = smallest(cur->next, end);
	if (ft_voidptr_icmp(cur->content, res->content) < 0)
		res = cur;
	return (res);
}
t_dlist	*mark(t_dlist *best)
{
	t_dlist	*cur;

	cur = best;
	while (cur != 0)
	{
		cur->flags = cur->flags | LEAVE_IN_A;
		if ((CUR_DEBUG & LIS_DEBUG) > 0)
		{
			iprinter(cur->content, cur->flags);
			ft_printf(" ");
		}
		cur = cur->lisn;
	}
	if ((CUR_DEBUG & LIS_DEBUG) > 0)
		ft_printf("\n");
	return (best);
}

t_dlist	*mark_lis(t_dlist *a, int asz)
{
	t_dlist	*cur;
	t_dlist	*best;
	int		checked;

	a = smallest(a, a);
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
			break ;
		cur = cur->next;
	}
	return (mark(best));
}
