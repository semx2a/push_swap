/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:29:12 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:57:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_pos(t_stack *stack)
{
	t_obj	o;

	o = (t_obj){0};
	o.tmp_hd = stack->head;
	o.i = 0;
	o.size = stack_size(stack);
	while (o.i < o.size)
	{
		o.tmp_hd->pos = o.i;
		o.i++;
		o.tmp_hd = o.tmp_hd->next;
	}
}

void	update_idx(t_stack *stack)
{
	t_obj	o;

	o = (t_obj){0};
	o.tmp_hd = stack->head;
	o.tmp_tl = stack->tail;
	o.i = 0;
	o.j = -1;
	o.size = stack_size(stack);
	while (o.i < o.size / 2)
	{
		o.tmp_hd->idx = o.i;
		o.tmp_tl->idx = o.j;
		o.i++;
		o.j--;
		o.tmp_hd = o.tmp_hd->next;
		o.tmp_tl = o.tmp_tl->prev;
	}
	if (o.size % 1 == 0)
		o.tmp_hd->idx = o.i;
	update_pos(stack);
}

void	put_back(t_stack *stack, int val, int idx, int pos)
{
	t_number	*new;

	new = xmalloc(sizeof(t_number));
	new->nb = val;
	new->idx = idx;
	new->pos = pos;
	new->prev = stack->tail;
	new->next = NULL;
	if (stack->tail)
		stack->tail->next = new;
	else
		stack->head = new;
	stack->tail = new;
}

void	put_front(t_stack *stack, int val, int idx, int pos)
{
	t_number	*new;

	new = xmalloc(sizeof(t_number));
	new->nb = val;
	new->idx = idx;
	new->pos = pos;
	new->next = stack->head;
	new->prev = NULL;
	if (stack->head)
		stack->head->prev = new;
	else
		stack->tail = new;
	stack->head = new;
}
