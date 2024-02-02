/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_ab_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:17:37 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 18:01:02 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

/* the last element becomes the first one */
void	reverse_reverse(t_stack *sa, t_stack *sb)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	if (stack_size(sa) > 1 && stack_size(sb) > 1)
	{
		a.tmp = sa->tail;
		b.tmp = sb->tail;
		if (!a.tmp || !b.tmp)
			exit(ft_error("checker: ", ERR));
		a.val = a.tmp->nb;
		b.val = b.tmp->nb;
		sa->tail = a.tmp->prev;
		sb->tail = b.tmp->prev;
		sa->tail->next = NULL;
		sb->tail->next = NULL;
		put_front(sa, a.val);
		put_front(sb, b.val);
		free(a.tmp);
		free(b.tmp);
	}
}

/* the first element becomes the last one */
void	rotate_rotate(t_stack *sa, t_stack *sb)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	if (stack_size(sa) > 1 && stack_size(sb) > 1)
	{
		a.tmp = sa->head;
		b.tmp = sb->head;
		if (!a.tmp || !b.tmp)
			exit(ft_error("checker: ", ERR));
		a.val = a.tmp->nb;
		b.val = b.tmp->nb;
		sa->head = a.tmp->next;
		sb->head = b.tmp->next;
		sa->head->prev = NULL;
		sb->head->prev = NULL;
		put_back(sa, a.val);
		put_back(sb, b.val);
		free(a.tmp);
		free(b.tmp);
	}
}

void	swap_swap(t_stack *sa, t_stack *sb)
{
	t_obj	a;
	t_obj	b;

	a = (t_obj){0};
	b = (t_obj){0};
	if (stack_size(sa) > 1 && stack_size(sb) > 1)
	{
		a.val = sa->head->nb;
		b.val = sa->head->next->nb;
		sa->head->nb = b.val;
		sa->head->next->nb = a.val;
		a.val = sb->head->nb;
		b.val = sb->head->next->nb;
		sb->head->nb = b.val;
		sb->head->next->nb = a.val;
	}
}
