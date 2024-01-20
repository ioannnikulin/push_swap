/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 16:24:28 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_dlist_clear(t_dlist **lst, void (*del)(void *), int ret)
{
	t_dlist	*cur;
	t_dlist	*n;
	int		lstlen;

	lstlen = ft_dlist_size(*lst);
	cur = *lst;
	while (lstlen --)
	{
		n = cur->next;
		del(cur->content);
		free(cur);
		cur = n;
	}
	*lst = 0;
	return (ret);
}
