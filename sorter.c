/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/02/10 16:07:33 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	sorted_impl(t_dlist *a, t_dlist *root)
{
	if (a->next == root)
		return (1);
	if (ft_voidptr_icmp(a->content, a->next->content) < 0)
		return (0);
	return (sorted_impl(a->next, root));
}

int	sorted(t_dlist *root)
{
	return (sorted_impl(root->next, root));
}

int	sort_turk(t_dlist **a, t_dlist **b);

int	sort(t_dlist **a, t_dlist **b)
{
	return (sort_turk(a, b));
}
