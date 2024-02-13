/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:56:28 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/13 17:16:35 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The sorted_arr function checks if the argument array is sorted.
If not sorted, the function simply returns so the algorithm can sort the array.
If it is already sorted, the program stops. */
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

/* The sorted_stack function returns 1 if the stack is sorted. 
If not, it returns 0. */
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

/* The checkup function returns the index of the first number that breaks
the stack's order. */
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

/* This function is the last one called for stacks bigger than five numbers.
It performs a verification to make sure all numbers are sorted 
in ascending order. */
void	final_check(t_stack *a)
{
	t_number	*tmp_a;
	int			i;

	tmp_a = a->head;
	update_idx(a);
	i = checkup(tmp_a);
	while (i != 0)
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
