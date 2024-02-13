/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 22:50:58 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/13 19:33:43 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arr(char **av, int ac, int *arr)
{	
	long		value;
	int			i;

	i = 0;
	while (i < ac)
	{
		value = ft_atoli(av[i]);
		if (value > INT_MAX || value < INT_MIN)
			exit(ft_error("push_swap: ", ERR));
		arr[i] = value;
		i++;
	}
}

int	find_ret(int **tab, int size)
{
	int	ret;
	int	i;

	i = size - 1;
	ret = 0;
	if (tab)
	{
		while (i != 0)
		{
			if (tab[i][1] == 0 || tab[i][1] == -1 || tab[i][1] == 1)
				ret = tab[i][0];
			i--;
		}
	}
	free_tab(tab, size);
	return (ret);
}
