/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 19:21:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	print_node_and_check(t_dlist *cur, int debug_lvl, void (*p)(void *))
{
	int	ret;

	ret = 0;
	if (cur->prev != 0 && cur->prev->next != cur)
		ret = 1;
	if (cur->next != 0 && cur->next->prev != cur)
		ret = 1;
	if ((debug_lvl & ANGLES) > 0)
		ft_printf("< ");
	if ((debug_lvl & PREV) > 0)
		ft_printf("(%p) ", cur->prev);
	if ((debug_lvl & ADDR) > 0)
		ft_printf("[%p] ", cur);
	p(cur->content);
	if ((debug_lvl & NEXT) > 0)
		ft_printf(" (%p)", cur->next);
	if ((debug_lvl & ANGLES) > 0)
		ft_printf(" >");
	return (ret);
}

static int	print_check(t_dlist *err)
{
	if (err)
	{
		ft_printf("First inconsistency in links found at object %p\n", err);
		return (1);
	}
	ft_printf("Link incosistencies not found\n");
	return (0);
}

int	ft_dlist_print(t_dlist *lst, int debug_lvl, char *delim, void (*p)(void *))
{
	t_dlist	*cur;
	int		lstlen;
	t_dlist	*err;

	lstlen = ft_dlist_size(lst);
	cur = lst;
	err = 0;
	while (-- lstlen >= 0)
	{
		if (print_node_and_check(cur, debug_lvl, p) && !err)
			err = cur;
		ft_printf("%s", delim);
		cur = cur->next;
	}
	if ((debug_lvl & CHECK) > 0)
		return (print_check(err));
	return (0);
}
