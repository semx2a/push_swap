/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:08:16 by seozcan           #+#    #+#             */
/*   Updated: 2022/03/15 19:08:18 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
