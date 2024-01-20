/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_add_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/20 20:32:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_dlist_add_front(t_dlist **lst, t_dlist *new)
{
	t_dlist *last;

	if (!(*lst))
	{
		new->next = *lst;
		(*lst)->prev = new;
		*lst = new;
		return ;
	}
	last = ft_dlist_last(*lst);
	new->next = *lst;
	new->prev = last;
	new->prev->next = new;
	new->next->prev = new;
	*lst = new;
}
