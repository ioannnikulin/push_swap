/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:28:14 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/17 18:06:39 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

int	print(t_dlist *a, t_dlist *b, void (*p)(void *))
{
	char	delim[2];
	int		ret;

	delim[0] = ' ';
	delim[1] = 0;
	if ((CUR_DEBUG & BORDER_PRINTOUT) > 0)
		ft_printf("\n================================");
	if ((CUR_DEBUG & NEWLINE_BETWEEN_ELEMENTS) > 0)
		delim[0] = '\n';
	if ((CUR_DEBUG & STACK_HEADER_FOOTER) > 0)
		ft_printf("\nStack A:\n");
	ret = ft_dlist_print(a, CUR_DEBUG, delim, p);
	if ((CUR_DEBUG & STACK_HEADER_FOOTER) > 0)
		ft_printf("\n--------\n");
	if ((CUR_DEBUG & STACK_HEADER_FOOTER) > 0)
		ft_printf("\nStack B:\n");
	ret = ret | ft_dlist_print(b, CUR_DEBUG, delim, p);
	if ((CUR_DEBUG & STACK_HEADER_FOOTER) > 0)
		ft_printf("\n--------\n");
	if ((CUR_DEBUG & BORDER_PRINTOUT) > 0)
		ft_printf("\n================================");
	ft_printf("\n");
	return (ret);
}

void	sprinter(void *content)
{
	ft_printf("%s", (char *)content);
}

void	iprinter(void *content)
{
	ft_printf("%i", (int)(intptr_t)content);
}
