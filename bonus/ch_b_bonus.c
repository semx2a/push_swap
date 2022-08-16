/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_b_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:17:44 by seozcan           #+#    #+#             */
/*   Updated: 2022/03/29 14:17:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	push_b(t_stack *a, t_stack *b)
{	
	t_node	*tmp;
	int		val;

	if (stack_size(a) != 0)
	{
		tmp = a->head;
		if (!tmp)
			ft_error(ERR);
		val = tmp->nb;
		put_front(b, val);
		a->head = a->head->next;
		if (a->head)
			a->head->prev = NULL;
		free(tmp);
	}
}

/* the last element becomes the first one */
void	reverse_b(t_stack *b)
{
	int		val;
	t_node	*tmp;

	if (stack_size(b) > 1)
	{
		tmp = b->tail;
		if (!tmp)
			ft_error(ERR);
		val = tmp->nb;
		b->tail = tmp->prev;
		b->tail->next = NULL;
		put_front(b, val);
		free(tmp);
	}	
}

/* the first element becomes the last one */
void	rotate_b(t_stack *b)
{
	int		val;
	t_node	*tmp;

	if (stack_size(b) > 1)
	{
		tmp = b->head;
		if (!tmp)
			ft_error(ERR);
		val = tmp->nb;
		b->head = tmp->next;
		b->head->prev = NULL;
		put_back(b, val);
		free(tmp);
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
	}
}
