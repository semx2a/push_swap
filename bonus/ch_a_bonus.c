/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_a_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:17:30 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 18:00:51 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_a(t_stack *b, t_stack *a)
{
	t_number	*tmp;
	int		val;

	if (stack_size(b) != 0)
	{
		tmp = b->head;
		if (!tmp)
			exit(ft_error("checker: ", ERR));
		val = tmp->nb;
		put_front(a, val);
		b->head = b->head->next;
		if (b->head)
			b->head->prev = NULL;
		free(tmp);
	}
}

/* the last element becomes the first one */
void	reverse_a(t_stack *a)
{
	int		val;
	t_number	*tmp;

	if (stack_size(a) > 1)
	{
		tmp = a->tail;
		if (!tmp)
			exit(ft_error("checker: ", ERR));
		val = tmp->nb;
		a->tail = tmp->prev;
		a->tail->next = NULL;
		put_front(a, val);
		free(tmp);
	}
}

/* the first element becomes the last one */
void	rotate_a(t_stack *a)
{
	int		val;
	t_number	*tmp;

	if (stack_size(a) > 1)
	{
		tmp = a->head;
		if (!tmp)
			exit(ft_error("checker: ", ERR));
		val = tmp->nb;
		a->head = tmp->next;
		a->head->prev = NULL;
		put_back(a, val);
		free(tmp);
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
	}
}
