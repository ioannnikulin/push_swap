/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/03/15 21:10:35 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_turk_internal.h"

t_turk_rots	find_cheapest(t_turk_params *p, int toa);
int			send_cheapest(t_turk_params *p, t_turk_rots rs, int toa);
int			pour_into_a(t_turk_params *p);
int			debut(t_turk_params *p);

int	sort_turk(t_dlist **a, t_dlist **b)
{
	int				turns;
	t_turk_params	params;
	int				sent;

	params.asz = ft_dlist_size(*a);
	params.bsz = 0;
	params.a = a;
	params.b = b;
	turns = debut(&params);
	if ((CUR_DEBUG & STAGE_RESULT_PRINT) > 0)
		print(*a, *b, iprinter);
	if (turns >= 0)
		return (turns);
	turns = -turns;
	sent = 2;
	while (params.asz > params.lis_start->lisl)
	{
		turns += send_cheapest(&params, find_cheapest(&params, 0), 0);
		sent ++;
	}
	turns += pour_into_a(&params);
	if ((CUR_DEBUG & STAGE_RESULT_PRINT) > 0)
		print(*a, *b, iprinter);
	return (turns + 2);
}
