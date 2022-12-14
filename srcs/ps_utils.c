/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:01:02 by seozcan           #+#    #+#             */
/*   Updated: 2022/03/15 15:30:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atoli(const char *str)
{
	int		i;
	int		n;
	long	r;

	i = 0;
	n = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			n *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (n * r);
}

void	ft_error(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	*xmalloc(size_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (!tmp)
		ft_error(ERR);
	return (tmp);
}

int	**allocate_tab(int **tab, int size)
{
	int	i;

	i = 0;
	tab = xmalloc(sizeof(int *) * size);
	while (i < size)
	{
		tab[i] = xmalloc(sizeof(int) * 2);
		i++;
	}
	return (tab);
}

void	free_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
