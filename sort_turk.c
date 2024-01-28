/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inikulin <inikulin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:50:01 by inikulin          #+#    #+#             */
/*   Updated: 2024/01/28 17:55:05 by inikulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_internal.h"

typedef enum e_dir
{
	ASC, DESC
}	t_dir;

typedef struct t_turk_params
{
	t_dlist **a;
	t_dlist **b;
	t_dir	bdir;
	int		asz;
	int		*prices;
	t_list	*story;
	int		storysz;
}	t_turk_params;

static int	three(t_turk_params *p)
{
	(void)a; // TODO:
	return (0);
}

static void	calc_price(t_turk_params *p, t_dlist *obj)
{
	t_list	*story; // TODO: actually dont need to store story, just count ra+rb+rr, then opposites, plus one pb
	int		storysz;
	t_dlist *justunder;
	int		juncmp;
	int		jabcmp;

	justunder = *(p->b);
	juncmp = ft_voidptr_strcmp(obj->content, justunder->content);
	jabcmp = ft_voidptr_strcmp(justunder->prev->content, obj->content);
	if (bdir == ASC && juncmp > 0 && jabcmp < 0) rb;
	if ()
}

static int	send_cheapest(t_turk_params *p)
{
	t_dlist *d;
	int		c;

	d = p->a;
	c = 0;
	while (c < p->asz)
	{
		calc_price(p, d);
		d = d->next;
		c ++;
	}
	while (-- p->storysz)
		apply(p->a, p->b, p->cand->ops);
}

static int	pour_into_a(t_turk_params *p)
{
	(void)a; // TODO:
	(void)b;
	return(0);
}

static int	debut(t_turk_params *p)
{
	if (p->asz < 2 || sorted(*(p->a)))
		return (0);
	if (p->asz == 2)
	{
		op_sa(*(p->a));
		return (1);
	}
	if (p->asz == 3)
		return (three(p));
	op_pb(*(p->a), *(p->b));
	if (sorted(*(p->a)))
		return (1 + pour_into_a(p));
	op_pb(*(p->a), *(p->b));
	if (sorted(*(p->a)))
		return (2 + pour_into_a(p));
	return (-1);
}

int	sort_turk(t_dlist **a, t_dlist **b)
{
	int				turns;
	t_turk_params	params;

	params.asz = ft_dlist_size(*a);
	turns = debut(&params);
	if (turns != -1)
		return (turns);
	params.asz -= 2;
	params.prices = malloc(params.asz * sizeof(int));
	if (!params.prices)
		return (error(0, &params));
	while (params.asz > 3)
		turns += send_cheapest(params);
	turns += pour_into_a(p);
	return (turns + 2);
}
