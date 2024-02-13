/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ab.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:17:37 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/13 19:10:56 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* the last element becomes the first one */
void	reverse_reverse(t_stack *sa, t_stack *sb)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	if (stack_size(sa) > 1 && stack_size(sb) > 1)
	{
		a.tmp = sa->tail;
		b.tmp = sb->tail;
		if (!a.tmp || !b.tmp)
			exit(ft_error("push_swap: ", ERR));
		a.val = a.tmp->nb;
		a.idx = a.tmp->idx;
		b.val = b.tmp->nb;
		b.idx = a.tmp->idx;
		sa->tail = a.tmp->prev;
		sb->tail = b.tmp->prev;
		sa->tail->next = NULL;
		sb->tail->next = NULL;
		put_front(sa, a.val, a.idx, 0);
		put_front(sb, b.val, b.idx, 0);
		free(a.tmp);
		free(b.tmp);
		ft_printf("rrr\n");
	}
}

/* the first element becomes the last one */
void	rotate_rotate(t_stack *sa, t_stack *sb)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	if (stack_size(sa) > 1 && stack_size(sb) > 1)
	{
		a.tmp = sa->head;
		b.tmp = sb->head;
		if (!a.tmp || !b.tmp)
			exit(ft_error("push_swap: ", ERR));
		a.val = a.tmp->nb;
		b.val = b.tmp->nb;
		sa->head = a.tmp->next;
		sb->head = b.tmp->next;
		sa->head->prev = NULL;
		sb->head->prev = NULL;
		put_back(sa, a.val, a.idx, stack_size(sa) - 1);
		put_back(sb, b.val, b.idx, stack_size(sb) - 1);
		free(a.tmp);
		free(b.tmp);
		ft_printf("rr\n");
	}
}

void	swap_swap(t_stack *sa, t_stack *sb)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	if (stack_size(sa) > 1 && stack_size(sb) > 1)
	{
		a.val = sa->head->nb;
		b.val = sa->head->next->nb;
		sa->head->nb = b.val;
		sa->head->next->nb = a.val;
		a.val = sb->head->nb;
		b.val = sb->head->next->nb;
		sb->head->nb = b.val;
		sb->head->next->nb = a.val;
		ft_printf("ss\n");
	}
}

/* This function perfoms double reverses or double rotates while the indexes
in arr[0] (i.e. Stack A index) and arr[1] (i.e. Stack B index) differ from 0.
If either of the indexes reaches 0, the algorithm stop and returns the modified
array*/
int	*mv_ab(t_stack *a, t_stack *b, int *arr)
{
	if (arr[0] < 0 && arr[1] < 0)
	{
		while (arr[0] != 0 && arr[1] != 0)
		{
			reverse_reverse(a, b);
			arr[0] += 1;
			arr[1] += 1;
		}
	}
	else if (arr[0] > 0 && arr[1] > 0)
	{
		while (arr[0] != 0 && arr[1] != 0)
		{
			rotate_rotate(a, b);
			arr[0] -= 1;
			arr[1] -= 1;
		}
	}
	return (arr);
}
