/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:00:55 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 19:18:18 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_main m)
{
	sorted_arr(m.size - 1, m.arr);
	init_stack(m.a);
	fill_stack(m.a, m.arr, m.size);
	if (!reverse_sorted_stack(m.a))
		return ;
	init_stack(m.b);
	if (m.size <= 3)
		sort_three(m.a);
	else if (m.size <= 5)
		sort_five(m.a, m.b);
	else
	{
		pre_sort(m.a, m.b);
		sort(m.a, m.b);
		final_check(m.a);
	}
}

int	main(int ac, char **av)
{
	t_main	m;

	m = (t_main){0};
	if (ac < 2)
		return (0);
	m.a = xmalloc(sizeof(t_stack));
	m.b = xmalloc(sizeof(t_stack));
	m.arr = xmalloc(sizeof(int) * (ac - 1));
	m.size = ac - 1;
	args_check(av + 1);
	check_duplicates(av + 1);
	fill_arr(av + 1, m.size, m.arr);
	push_swap(m);
	free(m.arr);
	free_stack(m.a);
	if (m.b)
		free(m.b);
	return (0);
}
