/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_update_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:29:12 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:57:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	put_back(t_stack *stack, int val)
{
	t_number	*new;

	new = xmalloc(sizeof(t_number));
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
	t_number	*new;

	new = xmalloc(sizeof(t_number));
	new->nb = val;
	new->next = stack->head;
	new->prev = NULL;
	if (stack->head)
		stack->head->prev = new;
	else
		stack->tail = new;
	stack->head = new;
}
