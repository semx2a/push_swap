/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bestmv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:18:27 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/14 15:15:02 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function determines which of the two selected indexes is the less 
expensive in terms of moves by comparing the computed values.*/
static int	*bestmv(t_obj *l, t_obj *h, int **tab)
{
	l->arr = xmalloc(sizeof(int) * 2);
	if (l->val < h->val)
	{
		l->arr[0] = tab[l->pos][0];
		l->arr[1] = tab[l->pos][1];
	}
	else
	{
		l->arr[0] = tab[h->pos][0];
		l->arr[1] = tab[h->pos][1];
	}
	return (l->arr);
}

static void	put_valpos(t_obj *l, t_obj *h, int *arr, int size)
{
	if (l->val > arr[l->i])
	{
		l->val = arr[l->i];
		l->pos = l->i;
	}
	if (size % 1 == 0 && l->i == (size / 2))
		return ;
	if (h->val > arr[h->j])
	{
		h->val = arr[h->j];
		h->pos = h->j;
	}
}

/* This function performs tests to find the 2 best moves in stack B:
To do that, it goes through all pairs of indexes stored in the tab array 
- one starts from top to middle
- the other starts from bottom to middle */
int	*find_bestmv(int *arr, int **tab, int size)
{
	t_obj	l;
	t_obj	h;

	l = (t_obj){0};
	h = (t_obj){0};
	h.j = (size - 1);
	h.pos = h.j;
	l.val = arr[l.i];
	h.val = arr[h.j];
	while (l.i <= (size / 2))
	{
		put_valpos(&l, &h, arr, size);
		l.i++;
		h.j--;
	}
	free(arr);
	l.arr = bestmv(&l, &h, tab);
	return (l.arr);
}
