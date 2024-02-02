/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:27 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:57:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
}

void	fill_stack(t_stack *stack, int *arr, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		put_back(stack, arr[i], 0, i);
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_number	*tmp;

	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
	stack->head = NULL;
	stack->tail = NULL;
	free(stack);
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_number	*tmp;

	size = 0;
	tmp = stack->head;
	if (stack)
	{
		if (tmp)
		{
			while (tmp)
			{
				tmp = tmp->next;
				size++;
			}
			return (size);
		}
	}
	return (0);
}
