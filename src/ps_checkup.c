/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:56:28 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 19:41:38 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_arr(int size, int *arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] < arr[i + 1])
			i++;
		else
			return ;
	}
	exit(EXIT_SUCCESS);
}

int	sorted_stack(t_stack *stack)
{
	t_number	*tmp;

	tmp = stack->head;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->nb < tmp->next->nb)
				tmp = tmp->next;
			else
				return (1);
		}
	}
	return (0);
}

int	reverse_sorted_stack(t_stack *stack)
{
	t_number	*tmp;
	int			i;

	tmp = stack->head;
	if (tmp)
	{
		while (tmp->next)
		{
			if (tmp->nb > tmp->next->nb)
				tmp = tmp->next;
			else
				return (1);
		}
	}
	i = stack_size(stack) - 1;
	while (i > 0)
	{
		rotate_a(stack);
		i--;
	}
	final_check(stack);
	return (0);
}

static int	checkup(t_number *tmp)
{
	while (tmp->next)
	{
		if (tmp->nb < tmp->next->nb)
			tmp = tmp->next;
		else
			return (tmp->next->idx);
	}
	return (0);
}

void	final_check(t_stack *a)
{
	t_number	*tmp_a;
	int		i;

	tmp_a = a->head;
	update_idx(a);
	i = checkup(tmp_a);
	printf("i = %d\n", i);
	while (i != 0 && i != -1)
	{
		if (i < 0)
		{
			reverse_a(a);
			i++;
		}
		else
		{
			rotate_a(a);
			i--;
		}
	}
}
