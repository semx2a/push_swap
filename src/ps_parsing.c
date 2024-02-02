/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:08:16 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 18:01:32 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				exit(ft_error("push_swap: ", ERR));
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
					exit(ft_error("push_swap: ", ERR));
			}
			if (ft_isdigit(av[o.i][o.j]))
				o.j++;
			else
				exit(ft_error("push_swap: ", ERR));
		}
		o.i++;
		o.j = 0;
	}
}
