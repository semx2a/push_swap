/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:51:59 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/14 15:11:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function return 1 if the indexes are both positive or both positive.
Else, it retuns 0. */
static int	is_comb(int i, int j)
{
	return ((i > 0 && j > 0) || (i < 0 && j < 0));
}

static int	absolute_val(int i)
{
	if (i < 0)
		i *= -1;
	return (i);
}

/* This function selects the heaviest number when comparing stack A's and B's 
indexes.
Because they are either both positive or negative, the algorithm will only
perform the number of moves represented by the heaviest index.*/
static void	put_comb(t_obj *o, int **tab)
{
	if (tab[o->i][0] > 0)
	{
		if (tab[o->i][0] < tab[o->i][1])
			o->arr[o->i] = tab[o->i][1];
		else
			o->arr[o->i] = tab[o->i][0];
	}
	else
	{
		if (tab[o->i][0] > tab[o->i][1])
			o->arr[o->i] = absolute_val(tab[o->i][1]);
		else
			o->arr[o->i] = absolute_val(tab[o->i][0]);
	}
}

/* This function computes the result of the equation of stack A's index 
with Stack B's index.
Because both the indexes are of opposite values, they are added to each other,
since their usage is the most expensive in terms of moves.*/
static void	combine(t_obj *o, int **tab)
{
	if (tab[o->i][0] < 0)
		o->arr[o->i] = absolute_val(tab[o->i][0]) + tab[o->i][1];
	else if (tab[o->i][1] < 0)
		o->arr[o->i] = tab[o->i][0] + absolute_val(tab[o->i][1]);
	else
		o->arr[o->i] = tab[o->i][0] + tab[o->i][1];
}

/* This function computes the total number of moves to be perfomed for each 
element and stores the result in and array.
The result may vary depending on the positivity of the indexes.
1- If both indexes are positive or negative, they go through the put_comb function.
2- Else if both indexes both negative and positive, they will go through the combine function.
3- Once the oprations have been perfomed on all pairs, the find_bestmv function is
called to allocate an array of 2, correponding to the indexes that will allow the
sorting algorithm to perform the moves.*/
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
	o.arr = find_bestmv(o.arr, tab, size);
	return (o.arr);
}
