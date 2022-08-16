/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:08:16 by seozcan           #+#    #+#             */
/*   Updated: 2022/03/15 19:08:18 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	find_mv(int i, t_stack *a, t_stack *b)
{
	if (i == 0)
		swap_a(a);
	else if (i == 1)
		push_a(b, a);
	else if (i == 2)
		rotate_a(a);
	else if (i == 3)
		reverse_a(a);
	else if (i == 4)
		swap_b(b);
	else if (i == 5)
		push_b(a, b);
	else if (i == 6)
		rotate_b(b);
	else if (i == 7)
		reverse_b(b);
	else if (i == 8)
		reverse_reverse(a, b);
	else if (i == 9)
		rotate_rotate(a, b);
	else if (i == 10)
		swap_swap(a, b);
	else if (i >= 11)
		ft_error(ERR);
}

int	check_mv(char *str, char **src)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (11);
		i++;
	}
	i = 0;
	while ((ft_strncmp(str, src[i], ft_strlen(src[i])) != 0))
		i++;
	return (i);
}

void	fill_arr(char **av, int ac, int *arr)
{	
	long		value;
	int			i;

	i = 0;
	while (i < ac)
	{
		value = ft_atoli(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			ft_error(ERR);
		arr[i] = value;
		i++;
	}
}

void	check_duplicates(char **av)
{
	t_obj	o;

	o = (t_obj){0};
	o.j = 1;
	while (av[o.i])
	{
		while (av[o.j])
		{
			if (ft_atoi(av[o.i]) == ft_atoi(av[o.j]))
				ft_error(ERR);
			o.j++;
		}
		o.i++;
		o.j = 1 + o.i;
	}
}

void	args_check(char **av)
{
	t_obj	o;

	o = (t_obj){0};
	while (av[o.i])
	{
		while (av[o.i][o.j])
		{
			while (av[o.i][o.j] == ' ')
				o.j++;
			if (av[o.i][o.j] == '-' || av[o.i][o.j] == '+')
			{
				o.j++;
				if (av[o.i][o.j] == '-' || av[o.i][o.j] == '+')
					ft_error(ERR);
			}
			if (ft_isdigit(av[o.i][o.j]))
				o.j++;
			else
				ft_error(ERR);
		}
		o.i++;
		o.j = 0;
	}
}
