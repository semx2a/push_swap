/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:19:18 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/13 20:32:03 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Find the smallest and biggest numbers of the stack and stores them in
a two dimentional array, where arr[0] stores the smallest number, and arr[1]
stores the biggest number.*/
static int	*find_minmax(t_stack *s)
{
	t_number	*tmp;
	int		*arr;
	int		min;
	int		max;

	tmp = s->head;
	arr = xmalloc(sizeof(int) * 2);
	min = tmp->nb;
	max = tmp->nb;
	while (tmp)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
	}
	arr[0] = min;
	arr[1] = max;
	return (arr);
}

/* This function simulates the final placement of stack B numbers into stack A
1- It allocates a two dimentional array of stack B's size.
2- The minmax function is called to find the smallest and biggest numbers 
in stack A
3- The idx_alloc function allocates the index of stack B's numbers in stack A 
4- The ret_alloc function returns the result of the bestmv function, an array 
of 2 integers, where arr[0] is the stack A's index and arr[1] is the stack B's 
index
5- The two dimentional array is freed
6- The array of 2 is returned
*/
static int	*find_idx(t_stack *sa, t_stack *sb, int size)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	a.tab = allocate_tab(a.tab, size);
	b.tmp = sb->head;
	a.tmp = sa->head;
	a.arr = find_minmax(sa);
	if (!b.tmp || !a.tmp || !a.arr)
		exit(ft_error("push_swap: ", ERR));
	idx_alloc(a, b, sa);
	free(a.arr);
	a.arr = ret_alloc(sb, a.tab, size);
	free_tab(a.tab, size);
	return (a.arr);
}

/* Sort stack of 3 numbers and less */
void	sort_three(t_stack *a)
{
	while (sorted_stack(a) != 0)
	{	
		if (a->head->nb > a->head->next->nb)
			swap_a(a);
		else if (a->head->next->nb > a->tail->nb)
			reverse_a(a);
		else if (a->head->nb > a->tail->nb)
			rotate_a(a);
	}
}

/* Sort stack of 5 numbers and less: 
1. Find the smallest and biggest numbers of the stack.
2. Push these two numbers into stack 
3. Sort the 3 remaining numbers with the sort_three algorithm
4. Push and place the smallest and biggest numbers back into stack A*/
void	sort_five(t_stack *a, t_stack *b)
{
	int	*arr;
	int	i;

	arr = find_minmax(a);
	i = 0;
	while (i != 2)
	{
		if (a->head->nb == arr[0] || a->head->nb == arr[1])
		{
			push_b(a, b);
			i++;
		}
		else
			rotate_a(a);
	}
	sort_three(a);
	while (b->head)
	{
		if (b->head->nb == arr[1] && stack_size(b) > 1)
			rotate_b(b);
		push_a(b, a);
	}
	if (a->head->nb == arr[1])
		rotate_a(a);
	free(arr);
}

/* This function sorts stacks bigger than 5 numbers by performing the following
actions: 
1- Update the B stack's size
2- Update the indexes in both A and B stack
3- Find the indexes both in A and B stack that requires the less moves, and
stores them in a two dimentional array where 
	arr[0] == Stack A's index
	arr[0] == Stack B's index
4- mv_ab performs either double reverse or double rotates and updates each
dimention of the array depending on the number of actions it performed.
5- mv_b either reverses or rotates Stack B depending on the number left in arr[1]
6- mv_a either reverses or rotates Stack A depending on the number left in arr[0]
7- push_a transfers the top number of Stack B into Stack A, finalizing a round 
of sorting
This sequence repeats itself until stack B is empty.
The resulting stack is sorted with no regards to ascending or descending order,
but is defintely sorted. */
void	sort(t_stack *a, t_stack *b)
{
	t_obj	o;

	o = (t_obj){0};
	while (b->head)
	{
		o.size = stack_size(b);
		update_idx(a);
		update_idx(b);
		o.arr = find_idx(a, b, o.size);
		o.arr = mv_ab(a, b, o.arr);
		mv_b(b, o.arr[1]);
		mv_a(a, o.arr[0]);
		push_a(b, a);
		free(o.arr);
	}
}
