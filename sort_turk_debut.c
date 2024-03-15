/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_debut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/15 21:11:30 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

int			three(t_dlist **a);
t_dlist		*mark_lis(t_dlist *a, int asz);
int			pour_into_a(t_turk_params *p);
int			send_one_to_b(t_turk_params *p);

int	debut(t_turk_params *p)
{
	int	turns;

	if (p->asz < 2 || sorted(*(p->a)) == p->asz)
		return (0);
	if (p->asz == 2)
	{
		op_sa(p->a);
		return (1);
	}
	if (p->asz == 3)
		return (three(p->a) + pour_into_a(p));
	p->lis_start = mark_lis(*(p->a), p->asz);
	if (p->lis_start->lisl == p->asz)
		return (pour_into_a(p));
	turns = send_one_to_b(p);
	if (p->lis_start->lisl == p->asz)
		return (turns + pour_into_a(p));
	if (p->asz == 3)
		return (three(p->a) + pour_into_a(p));
	turns += send_one_to_b(p);
	if (p->lis_start->lisl == p->asz)
		return (turns + pour_into_a(p));
	if (p->asz == 3)
		return (three(p->a) + pour_into_a(p));
	return (-turns);
}
