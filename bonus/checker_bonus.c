/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:27:01 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 16:59:28 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static char	**mv_alloc(char **src)
{
	src = xmalloc(sizeof(char *) * 13);
	src[0] = ft_strdup("sa");
	src[1] = ft_strdup("pa");
	src[2] = ft_strdup("ra");
	src[3] = ft_strdup("rra");
	src[4] = ft_strdup("sb");
	src[5] = ft_strdup("pb");
	src[6] = ft_strdup("rb");
	src[7] = ft_strdup("rrb");
	src[8] = ft_strdup("rrr");
	src[9] = ft_strdup("rr");
	src[10] = ft_strdup("ss");
	src[11] = ft_strdup("Error");
	src[12] = 0;
	return (src);
}

static void	push_swap(t_main m)
{
	init_stack(m.a);
	init_stack(m.b);
	fill_stack(m.a, m.arr, m.size);
	m.fd = 0;
	m.str = get_next_line(m.fd);
	m.src = mv_alloc(m.src);
	while (m.str)
	{
		m.i = check_mv(m.str, m.src);
		find_mv(m.i, m.a, m.b);
		free(m.str);
		m.str = get_next_line(m.fd);
	}
	free(m.str);
	free_strtab((m.src), ft_tablen(m.src));
	checkup(m.a);
}

int	main(int ac, char **av)
{
	t_main	m;

	m = (t_main){0};
	if (ac < 2)
		return (0);
	m.a = xmalloc(sizeof(t_stack));
	m.b = xmalloc(sizeof(t_stack));
	m.arr = xmalloc(sizeof(int) * (ac - 1));
	m.size = ac - 1;
	args_check(av + 1);
	check_duplicates(av + 1);
	fill_arr(av + 1, m.size, m.arr);
	push_swap(m);
	free(m.arr);
	free_stack(m.a);
	free_stack(m.b);
	return (0);
}
