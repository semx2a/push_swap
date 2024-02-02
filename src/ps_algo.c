/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:19:18 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 18:01:32 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*find_minmax(t_stack *s)
{
	t_number	*tmp;
	int		*arr;
	int		min;
	int		max;

	tmp = s->head;
	arr = xmalloc(sizeof(int) * 2);
	min = tmp->nb;
	max = tmp->nb;
	while (tmp)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
	}
	arr[0] = min;
	arr[1] = max;
	return (arr);
}

/* simuler le placement final de toute la stack b dans la stack a */
static int	*find_idx(t_stack *sa, t_stack *sb, int size)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	a.tab = allocate_tab(a.tab, size);
	b.tmp = sb->head;
	a.tmp = sa->head;
	a.arr = find_minmax(sa);
	if (!b.tmp || !a.tmp || !a.arr)
		exit(ft_error("push_swap: ", ERR));
	idx_alloc(a, b, sa);
	free(a.arr);
	a.arr = ret_alloc(sb, a.tab, size);
	free_tab(a.tab, size);
	return (a.arr);
}

void	sort_three(t_stack *a)
{
	while (sorted_stack(a) != 0)
	{	
		if (a->head->nb > a->head->next->nb)
			swap_a(a);
		else if (a->head->next->nb > a->tail->nb)
			reverse_a(a);
		else if (a->head->nb > a->tail->nb)
			rotate_a(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	*arr;
	int	i;

	arr = find_minmax(a);
	i = 0;
	while (i != 2)
	{
		if (a->head->nb == arr[0] || a->head->nb == arr[1])
		{
			push_b(a, b);
			i++;
		}
		else
			rotate_a(a);
	}
	sort_three(a);
	while (b->head)
	{
		if (b->head->nb == arr[1] && stack_size(b) > 1)
			rotate_b(b);
		push_a(b, a);
	}
	if (a->head->nb == arr[1])
		rotate_a(a);
	free(arr);
}

void	sort(t_stack *a, t_stack *b)
{
	t_obj	o;

	o = (t_obj){0};
	while (b->head)
	{
		o.size = stack_size(b);
		update_idx(a);
		update_idx(b);
		o.arr = find_idx(a, b, o.size);
		o.arr = mv_ab(a, b, o.arr);
		mv_b(b, o.arr[1]);
		mv_a(a, o.arr[0]);
		push_a(b, a);
		free(o.arr);
	}
}
