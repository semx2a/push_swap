/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:59 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 16:59:28 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_comb(int i, int j)
{
	if ((i > 0 && j > 0) || (i < 0 && j < 0))
		return (1);
	return (0);
}

static int	absolute_val(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

static void	put_comb(t_obj *o, int **tab)
{
	if (tab[o->i][0] > 0)
	{
		if (tab[o->i][0] > tab[o->i][1])
			o->arr[o->i] = tab[o->i][0];
		else if (tab[o->i][0] < tab[o->i][1])
			o->arr[o->i] = tab[o->i][1];
		else
			o->arr[o->i] = tab[o->i][0];
	}
	else
	{
		if (tab[o->i][0] < tab[o->i][1])
			o->arr[o->i] = absolute_val(tab[o->i][0]);
		else if (tab[o->i][0] > tab[o->i][1])
			o->arr[o->i] = absolute_val(tab[o->i][1]);
		else
			o->arr[o->i] = absolute_val(tab[o->i][0]);
	}
}

static void	combine(t_obj *o, int **tab)
{
	if (tab[o->i][0] < 0)
		o->arr[o->i] = (tab[o->i][0] * -1) + tab[o->i][1];
	else if (tab[o->i][1] < 0)
		o->arr[o->i] = tab[o->i][0] + (tab[o->i][1] * -1);
	else
		o->arr[o->i] = tab[o->i][0] + tab[o->i][1];
}

int	*ret_alloc(t_stack *b, int **tab, int size)
{
	t_obj	o;

	o = (t_obj){0};
	o.i = 0;
	o.arr = xmalloc(sizeof(int) * size);
	o.tmp = b->head;
	while (o.tmp)
	{
		if (is_comb(tab[o.i][0], tab[o.i][1]) == 1)
			put_comb(&o, tab);
		else
			combine(&o, tab);
		if (o.arr[o.i] < 0)
			o.arr[o.i] *= -1;
		o.tmp = o.tmp->next;
		o.i++;
	}
	o.arr = find_bestmv(b, o.arr, tab, size);
	return (o.arr);
}
