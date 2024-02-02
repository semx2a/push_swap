/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:17:30 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 18:01:32 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *b, t_stack *a)
{
	t_number	*tmp;
	int		val;
	int		idx;

	if (stack_size(b) != 0)
	{
		tmp = b->head;
		if (!tmp)
			exit(ft_error("push_swap: ", ERR));
		val = tmp->nb;
		idx = tmp->idx;
		put_front(a, val, idx, 0);
		b->head = b->head->next;
		if (b->head)
			b->head->prev = NULL;
		free(tmp);
		ft_printf("pa\n");
	}
}

/* the last element becomes the first one */
void	reverse_a(t_stack *a)
{
	int		val;
	int		idx;
	t_number	*tmp;

	if (stack_size(a) > 1)
	{
		tmp = a->tail;
		if (!tmp)
			exit(ft_error("push_swap: ", ERR));
		val = tmp->nb;
		idx = tmp->idx;
		a->tail = tmp->prev;
		a->tail->next = NULL;
		put_front(a, val, idx, 0);
		free(tmp);
		ft_printf("rra\n");
	}
}

/* the first element becomes the last one */
void	rotate_a(t_stack *a)
{
	int		val;
	int		idx;
	t_number	*tmp;

	if (stack_size(a) > 1)
	{
		tmp = a->head;
		if (!tmp)
			exit(ft_error("push_swap: ", ERR));
		val = tmp->nb;
		idx = tmp->idx;
		a->head = tmp->next;
		a->head->prev = NULL;
		put_back(a, val, idx, stack_size(a) - 1);
		free(tmp);
		ft_printf("ra\n");
	}
}

void	swap_a(t_stack *a)
{
	int	val1;
	int	val2;

	if (stack_size(a) > 1)
	{
		val1 = a->head->nb;
		val2 = a->head->next->nb;
		a->head->nb = val2;
		a->head->next->nb = val1;
		ft_printf("sa\n");
	}
}

void	mv_a(t_stack *a, int i)
{
	while (i != 0)
	{	
		if (i < 0)
		{
			reverse_a(a);
			i += 1;
		}
		else
		{
			rotate_a(a);
			i -= 1;
		}
	}
}
