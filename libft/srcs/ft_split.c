/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:23:41 by seozcan           #+#    #+#             */
/*   Updated: 2021/11/30 19:30:07 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static size_t	ft_count(char const *s, char a)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] && s[i] != a)
	{
		count++;
		i++;
	}
	return (count);
}

static void	ft_freed(char **d, size_t j)
{
	while (j)
	{
		free(d[j]);
		j--;
	}
	free(d);
}

static void	ft_substrcpy(char const *s, char a, char **d)
{	
	size_t	w_count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (ft_count(s + i, a))
		{
			w_count = 0;
			w_count = ft_count(s + i, a);
			d[j] = ft_substr(s + i, 0, w_count);
			if (ft_strlen(d[j]) != w_count)
				return (ft_freed(d, j));
			i = i + w_count;
			j++;
		}
		i++;
	}
}

char	**ft_split(char const *s, char a)
{
	char		**d;
	size_t		t_count;
	int			i;

	if (!s)
		return (NULL);
	t_count = 0;
	d = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != a && (!s[i + 1] || s[i + 1] == a))
			t_count++;
		i++;
	}
	d = (char **)malloc(sizeof(char *) * (t_count + 1));
	if (!d)
		return (NULL);
	ft_substrcpy(s, a, d);
	d[t_count] = 0;
	return (d);
}
