/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_presort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:55:11 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/12 18:59:31 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_median(t_stack *s)
{
	t_obj	o;

	o = (t_obj){0};
	o.tab = allocate_tab(o.tab, stack_size(s));
	o.tmp_hd = s->head;
	o.tmp_tl = s->tail;
	while (o.tmp_hd)
	{
		while (o.tmp_tl)
		{
			if (o.tmp_tl->nb < o.tmp_hd->nb)
				o.j++;
			else if (o.tmp_tl->nb > o.tmp_hd->nb)
				o.j--;
			o.tmp_tl = o.tmp_tl->prev;
		}
		o.tab[o.i][0] = o.tmp_hd->nb;
		o.tab[o.i][1] = o.j;
		o.tmp_tl = s->tail;
		o.tmp_hd = o.tmp_hd->next;
		o.j = 0;
		o.i++;
	}
	o.ret = find_ret(o.tab, stack_size(s));
	return (o.ret);
}

static void	hold_nb(t_obj *o)
{
	o->tmp->idx = -1;
	o->hold = o->tmp;
	o->i += 1;
}

/* finds the longest sorted number sequence in stack a */
static int	best_sqn(t_stack *a, int idx)
{
	t_obj	o;

	o = (t_obj){0};
	o.tmp = a->head;
	while (o.tmp->idx != idx)
		o.tmp = o.tmp->next;
	hold_nb(&o);
	idx--;
	while (o.tmp)
	{
		while (o.tmp)
		{	
			if (o.tmp->idx == idx && o.hold->nb < o.tmp->nb)
			{
				hold_nb(&o);
				break ;
			}
			o.tmp = o.tmp->next;
		}
		if (idx == 0)
			return (o.i);
		o.tmp = o.hold;
		idx--;
	}
	return (o.i);
}

/* finds the integer with the best potential for the longest sorted number 
sequence in stack a */
static int	find_sqn(t_stack *a)
{
	t_number	*tmp_a;
	t_number	*tmp_cmp;
	t_number	*hold;

	tmp_a = a->head;
	tmp_cmp = tmp_a->next;
	hold = a->head;
	while (tmp_a)
	{
		while (tmp_cmp)
		{
			if (tmp_a->nb < tmp_cmp->nb)
				tmp_a->idx += 1;
			tmp_cmp = tmp_cmp->next;
		}
		if (hold->idx < tmp_a->idx)
			hold = tmp_a;
		tmp_a = tmp_a->next;
		if (tmp_a != NULL)
			tmp_cmp = tmp_a->next;
	}
	return (hold->idx);
}

void	pre_sort(t_stack *a, t_stack *b)
{
	int	idx;
	int	med;
	int	i;

	idx = find_sqn(a);
	i = 1;
	if (idx != 0)
		i = best_sqn(a, idx);
	med = find_median(a);
	while (stack_size(a) != i)
	{
		if (a->head->idx == -1)
			rotate_a(a);
		else
		{
			push_b(a, b);
			if (stack_size(b) > 1 && b->head->nb < med)
				rotate_b(b);
		}
	}
}
