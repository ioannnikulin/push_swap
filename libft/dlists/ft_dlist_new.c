/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 19:01:40 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/02 20:08:06 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_dlist	*ft_dlist_new(void *content)
{
	t_dlist	*r;

	r = malloc(sizeof(t_dlist));
	if (!r)
		return (0);
	r->next = 0;
	r->prev = 0;
	r->lisl = 0;
	r->lisn = 0;
	r->content = content;
	r->flags = 0;
	return (r);
}
