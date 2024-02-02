/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:29:50 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 16:59:28 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_minmax(t_obj a, t_obj b)
{
	if (b.tmp->nb <= a.arr[0])
	{
		while (a.tmp && a.tmp->nb != a.arr[0])
			a.tmp = a.tmp->next;
		a.tab[a.i][0] = a.tmp->idx;
	}
	else if (b.tmp->nb >= a.arr[1])
	{
		while (a.tmp->next && a.tmp->nb != a.arr[1])
			a.tmp = a.tmp->next;
		if (a.tmp->next == NULL && b.tmp->nb > a.tmp->nb)
			a.tab[a.i][0] = 0;
		else
			a.tab[a.i][0] = a.tmp->next->idx;
	}
}

static void	isnt_minmax(t_obj a, t_obj b, t_stack *sa)
{
	while (a.tmp)
	{
		if (a.tmp->next == NULL)
		{
			if (b.tmp->nb > a.tmp->nb && b.tmp->nb > sa->head->nb)
				a.tab[a.i][0] = -1;
			break ;
		}
		else if (b.tmp->nb > a.tmp->nb && b.tmp->nb < a.tmp->next->nb)
		{
			a.tab[a.i][0] = a.tmp->next->idx;
			break ;
		}
		a.tmp = a.tmp->next;
	}
}

/*	allocates a tab with two entries, the size of stack b;
each entries corresponds to an integer in stack b, in ascending order;
tab[0] == the idx corresponding to the position this int should be located
in stack a;
tab[1] == the idx of the number in stack b we are trying to place */
void	idx_alloc(t_obj a, t_obj b, t_stack *sa)
{
	while (b.tmp)
	{
		a.tab[a.i][1] = b.tmp->idx;
		a.tab[a.i][0] = 0;
		if (b.tmp->nb <= a.arr[0] || b.tmp->nb >= a.arr[1])
			is_minmax(a, b);
		else
			isnt_minmax(a, b, sa);
		b.tmp = b.tmp->next;
		a.tmp = sa->head;
		a.i++;
	}
}
