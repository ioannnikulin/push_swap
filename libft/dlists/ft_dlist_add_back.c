/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 20:32:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlist_add_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*cur;

	cur = ft_dlist_last(*lst);
	if (!cur)
		*lst = new;
	else
	{
		new->next = cur->next;
		new->prev = cur;
		new->next->prev = new;
		new->prev->next = new;
	}
}