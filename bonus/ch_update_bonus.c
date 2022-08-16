/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:29:12 by seozcan           #+#    #+#             */
/*   Updated: 2022/04/20 16:29:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	put_back(t_stack *stack, int val)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->nb = val;
	new->prev = stack->tail;
	new->next = NULL;
	if (stack->tail)
		stack->tail->next = new;
	else
		stack->head = new;
	stack->tail = new;
}

void	put_front(t_stack *stack, int val)
{
	t_node	*new;

	new = xmalloc(sizeof(t_node));
	new->nb = val;
	new->next = stack->head;
	new->prev = NULL;
	if (stack->head)
		stack->head->prev = new;
	else
		stack->tail = new;
	stack->head = new;
}
