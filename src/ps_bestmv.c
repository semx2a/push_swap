/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bestmv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:18:27 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 16:59:28 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* determins which of the two selected moves is the less expensive */
static int	*bestmv(t_stack *b, t_obj *l, t_obj *h, int **tab)
{
	l->arr = xmalloc(sizeof(int) * 2);
	h->tmp_hd = b->head;
	h->tmp_tl = b->tail;
	while (h->tmp_hd->idx != tab[l->pos][1])
		h->tmp_hd = h->tmp_hd->next;
	while (h->tmp_tl->idx != tab[h->pos][1])
		h->tmp_tl = h->tmp_tl->prev;
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

/* looks for 2 best moves: 
- one idex starts from top to middle
- the other starts from bottom to middle */
int	*find_bestmv(t_stack *b, int *arr, int **tab, int size)
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
	l.arr = bestmv(b, &l, &h, tab);
	return (l.arr);
}
