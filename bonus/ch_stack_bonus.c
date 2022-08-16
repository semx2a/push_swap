/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_stack_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:14:27 by seozcan           #+#    #+#             */
/*   Updated: 2022/03/14 15:14:46 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	checkup(t_stack *a)
{
	t_node	*tmp;

	tmp = a->head;
	while (tmp->next)
	{
		if (tmp->nb < tmp->next->nb)
			tmp = tmp->next;
		else
		{
			ft_printf("KO\n");
			return ;
		}
	}
	ft_printf("OK\n");
}

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
		put_back(stack, arr[i]);
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

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
	t_node	*tmp;

	size = 0;
	if (stack)
	{
		tmp = stack->head;
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
