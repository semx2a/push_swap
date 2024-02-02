/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:17:44 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 18:01:32 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *a, t_stack *b)
{	
	t_number	*tmp;
	int		val;
	int		idx;

	if (stack_size(a) != 0)
	{
		tmp = a->head;
		if (!tmp)
			exit(ft_error("push_swap: ", ERR));
		val = tmp->nb;
		idx = tmp->idx;
		put_front(b, val, idx, 0);
		a->head = a->head->next;
		if (a->head)
			a->head->prev = NULL;
		free(tmp);
		ft_printf("pb\n");
	}
}

/* the last element becomes the first one */
void	reverse_b(t_stack *b)
{
	int		val;
	int		idx;
	t_number	*tmp;

	if (stack_size(b) > 1)
	{
		tmp = b->tail;
		if (!tmp)
			exit(ft_error("push_swap: ", ERR));
		val = tmp->nb;
		idx = tmp->idx;
		b->tail = tmp->prev;
		b->tail->next = NULL;
		put_front(b, val, idx, 0);
		free(tmp);
		ft_printf("rrb\n");
	}
}

/* the first element becomes the last one */
void	rotate_b(t_stack *b)
{
	int		val;
	int		idx;
	t_number	*tmp;

	if (stack_size(b) > 1)
	{
		tmp = b->head;
		if (!tmp)
			exit(ft_error("push_swap: ", ERR));
		val = tmp->nb;
		idx = tmp->idx;
		b->head = tmp->next;
		b->head->prev = NULL;
		put_back(b, val, idx, stack_size(b));
		free(tmp);
		ft_printf("rb\n");
	}
}

void	swap_b(t_stack *b)
{
	int	val1;
	int	val2;

	if (stack_size(b) > 1)
	{
		val1 = b->head->nb;
		val2 = b->head->next->nb;
		b->head->nb = val2;
		b->head->next->nb = val1;
		ft_printf("sa\n");
	}
}

void	mv_b(t_stack *b, int i)
{
	while (i != 0)
	{
		if (i < 0)
		{
			reverse_b(b);
			i += 1;
		}
		else
		{
			rotate_b(b);
			i -= 1;
		}
	}
}
