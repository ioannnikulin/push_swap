/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_ncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:41:58 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/27 14:35:47 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	strcmp(void *a, void *b)
{
	return (ft_strncmp((char *)a, (char *)b, ft_strlen((char *)a)));
}

static int	loop(t_dlist *a, t_dlist *b, int (*cmp)(void *, void *), int *cur)
{
	int	rs;

	rs = cmp(a->content, b->content);
	if (rs != 0)
	{
		if (rs < 0)
			(*cur) = -(*cur);
		return (1);
	}
	return (0);
}

int	ft_dlist_ncmp(t_dlist *a, t_dlist *b, int n, int (*cmp)(void *, void *))
{
	int	cur;
	int	alen;
	int blen;
	
	cur = 0;
	if (a == b)
		return (-1);
	alen = ft_dlist_size(a);
	blen = ft_dlist_size(b);
	while (cur < n && alen -- > 0 && blen -- > 0)
	{
		if (loop(a, b, cmp, &cur))
			return (cur);
	}
	if (alen < blen)
		return (-cur);
	if (alen > blen)
		return (cur);
	return (0);
}

int	ft_dlist_ncmp_str(t_dlist *a, t_dlist *b, int n)
{
	return (ft_dlist_ncmp(a, b, n, strcmp));
}
