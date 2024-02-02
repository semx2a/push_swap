/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:27:53 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/02 17:57:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H

# define CHECKER_BONUS_H

/*		LIBRARIES
		read, write, exit*/
# include <unistd.h>

/*		malloc, free	 */
# include <stdlib.h>

/*		libft			 */
# include "libft.h"

/*		ft_printf		 */
# include "ft_printf.h"

/*		ft_strlen_gnl	*/
# include <string.h>

/*		filedes 		*/
# include <stdio.h>

/*		ERROR			 */
# define ERR		"Error"
# define INT_MIN	-2147483648
# define INT_MAX	2147483647

/*		LINKED LISTS
		numbers structure	*/
typedef struct s_number
{
	int				nb;
	struct s_number	*prev;
	struct s_number	*next;
}	t_number;

/*		stack io		*/
typedef struct s_stack
{
	t_number	*head;
	t_number	*tail;
}	t_stack;

/*		STRUCTURES
		push_swap.c		*/
typedef struct s_main
{
	int		i;
	int		fd;
	int		size;
	int		*arr;
	char	*str;
	char	**src;
	t_stack	*a;
	t_stack	*b;
}	t_main;

/*		ps_parsing.c	*/
typedef struct s_obj
{
	int		i;
	int		j;
	int		val;
	int		*arr;
	int		**tab;
	t_number	*tmp;
}	t_obj;

/*		ch_parsing_bonus.c	*/
void	check_duplicates(char **av);
void	args_check(char **av);
void	fill_arr(char **av, int ac, int *arr);
int		check_mv(char *str, char **src);
void	find_mv(int i, t_stack *a, t_stack *b);

/*		ch_utils_bonus.c	*/
void	sorted_arr(int size, int *arr);
void	free_strtab(char **tab, int size);

/*		ch_stack_bonus.c	*/
void	init_stack(t_stack *stack);
void	fill_stack(t_stack *stack, int *arr, int size);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
void	checkup(t_stack *a);

/*		ch_update_bonus.c	*/
void	put_back(t_stack *stack, int val);
void	put_front(t_stack *stack, int val);
void	checkup(t_stack *a);

/*		ch_a_bonus.c		*/
void	push_a(t_stack *b, t_stack *a);
void	reverse_a(t_stack *a);
void	rotate_a(t_stack *a);
void	swap_a(t_stack *a);

/*		ch_b_bonus.c		*/
void	push_b(t_stack *a, t_stack *b);
void	reverse_b(t_stack *b);
void	rotate_b(t_stack *b);
void	swap_b(t_stack *b);

/*		ch_ab_bonus.c		*/
void	reverse_reverse(t_stack *sa, t_stack *sb);
void	rotate_rotate(t_stack *sa, t_stack *sb);
void	swap_swap(t_stack *sa, t_stack *sb);

/*		get_next_line.c		*/
char	*get_next_line(int fd);
char	*set_head(char *head);
char	*get_line(char *ln, char *head);
char	*append_lines(int fd, char *buff, char *head);

/*		get_next_line_utils.c	*/
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t	ft_strlen_gnl(const char *str);

#endif
