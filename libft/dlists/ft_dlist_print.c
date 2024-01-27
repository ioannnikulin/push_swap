/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 15:13:25 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	print_node_and_check(t_dlist *cur, int mode)
{
	int	ret;

	ret = 0;
	if (cur->prev != 0 && cur->prev->next != cur)
		ret = 1;
	if (cur->next != 0 && cur->next->prev != cur)
		ret = 1;
	if ((mode & ANGLES) > 0)
		ft_printf("< ");
	if ((mode & PREV) > 0)
		ft_printf("(%p) ", cur->prev);
	if ((mode & ADDR) > 0)
		ft_printf("[%p] ", cur);
	ft_printf("%s", (char *)(cur->content));
	if ((mode & NEXT) > 0)
		ft_printf(" (%p)", cur->next);
	if ((mode & ANGLES) > 0)
		ft_printf(" >");
	return (ret);
}

static void	print_check(t_dlist *err)
{
	if (err)
		ft_printf("First inconsistency in links found at object %p\n", err);
	else
		ft_printf("Link incosistencies not found\n");
}

void	ft_dlist_print(t_dlist *lst, int mode, char *delim)
{
	t_dlist	*cur;
	int		lstlen;
	t_dlist	*err;

	if (!lst)
		return ;
	lstlen = ft_dlist_size(lst);
	cur = lst;
	err = 0;
	while (-- lstlen >= 0)
	{
		if (print_node_and_check(cur, mode) && !err)
			err = cur;
		ft_printf("%s", delim);
		cur = cur->next;
	}
	if ((mode & CHECK) > 0)
		print_check(err);
}
