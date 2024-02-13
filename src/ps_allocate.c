/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:29:50 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/13 19:33:43 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This function tests if the stack B number being currently investigated is the
overall smallest or biggest number of stack A's current state.
It allocates tab[0] with the stack A's index. This index is the location of 
stack B's number in stack A*/
static void	is_minmax(t_obj a, t_obj b)
{
	if (b.tmp->nb <= a.arr[0])
	{
		while (a.tmp && a.tmp->nb != a.arr[0])
			a.tmp = a.tmp->next;
		if (a.tmp != NULL)
			a.tab[a.i][0] = a.tmp->idx;
	}
	else if (b.tmp->nb >= a.arr[1])
	{
		while (a.tmp->next && a.tmp->nb != a.arr[1])
			a.tmp = a.tmp->next;
		if (a.tmp->next == NULL && b.tmp->nb > a.tmp->nb)
			a.tab[a.i][0] = 0;
		else
			if (a.tmp->next != NULL)
				a.tab[a.i][0] = a.tmp->next->idx;
	}
}

/* This function tests where the stack B number being currently investigated
should be located in stack A.
The stack B number is neither the smallest nor the biggest number of 
stack A's current state */
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

/* This function takes two stacks and a pointer to stack A as arguments.
It searches the best position for each stack B numbers to be positionned in
stack A.
tab[pos][0] == the A stack index where the stack B number being investigated
should be located at;
tab[pos][1] == the stack B index of the number we are trying to allocate a slot for;
a.arr[0] == min of stack A;
a.arr[1] == max of stack A*/
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
