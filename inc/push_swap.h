/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:00:46 by seozcan           #+#    #+#             */
/*   Updated: 2022/03/09 12:00:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

/*		LIBRARIES
		read, write, exit*/
# include <unistd.h>

/*		malloc, free	 */
# include <stdlib.h>

/*		libft			 */
# include "../libft/inc/libft.h"

/*		ft_printf		 */
# include "../ft_printf/inc/ft_printf.h"

/*		ERROR			 */
# define ERR		"Error"
# define INT_MIN	-2147483648
# define INT_MAX	2147483647

/*		LINKED LISTS
		nodes structure	*/
typedef struct s_node
{
	int				nb;
	int				idx;
	int				pos;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

/*		stack io		*/
typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

/*		STRUCTURES
		push_swap.c		*/

typedef struct s_main
{
	int		size;
	int		*arr;
	t_stack	*a;
	t_stack	*b;
}	t_main;

/*		ps_parsing.c	*/
typedef struct s_obj
{
	int		i;
	int		j;
	int		size;
	int		val;
	int		idx;
	int		pos;
	int		ret;
	int		*arr;
	int		**tab;
	t_node	*tmp;
	t_node	*tmp_hd;
	t_node	*tmp_tl;
	t_node	*hold;
}	t_obj;

/*  	FUNCTIONS
		ps_stack.c		*/
void	init_stack(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_size(t_stack *stack);
void	fill_stack(t_stack *stack, int *arr, int size);

/*		ps_presort.c	*/
void	pre_sort(t_stack *a, t_stack *b);

/*		ps_checkup.c	*/
void	final_check(t_stack *a);
void	sorted_arr(int size, int *arr);
int		sorted_stack(t_stack *stack);

/*		ps_algo.c		*/
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);

/*		ps_array.c		*/
void	fill_arr(char **av, int ac, int *arr);
int		find_ret(int **tab, int size);

/*		ps_bestmv.c		*/
int		*find_bestmv(t_stack *b, int *arr, int **tab, int size);

/*		ps_compare.c	*/
int		*ret_alloc(t_stack *b, int **tab, int size);

/*		ps_utils.c		*/
int		**allocate_tab(int **tab, int size);
void	free_tab(int **tab, int size);
void	ft_error(const char *str);
void	*xmalloc(size_t size);
long	ft_atoli(const char *str);

/*		ps_allocate.c	*/
void	idx_alloc(t_obj a, t_obj b, t_stack *sa);

/*		ps_update.c		*/
void	update_idx(t_stack *stack);
void	put_back(t_stack *stack, int val, int idx, int pos);
void	put_front(t_stack *stack, int val, int idx, int pos);

/*		ps_parsing.c	*/
void	args_check(char **av);
void	check_duplicates(char **av);

/*		ps_a.c	*/
void	mv_a(t_stack *a, int i);
void	rotate_a(t_stack *a);
void	reverse_a(t_stack *a);
void	push_a(t_stack *b, t_stack *a);
void	swap_a(t_stack *a);

/*		ps_b.c		*/
void	mv_b(t_stack*b, int i);
void	rotate_b(t_stack *b);
void	reverse_b(t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	swap_b(t_stack *b);

/*		ps_ab.c		*/
void	rotate_rotate(t_stack *sa, t_stack *sb);
void	reverse_reverse(t_stack *sa, t_stack *sb);
void	swap_swap(t_stack *sa, t_stack *sb);
int		*mv_ab(t_stack *a, t_stack *b, int *arr);

#endif 
