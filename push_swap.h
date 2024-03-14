/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:48:02 by akloster          #+#    #+#             */
/*   Updated: 2024/02/05 12:01:19 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# define MAX 1
# define MIN -1

typedef struct s_stack
{
	int				target;
	int				value;
	int				content;
	int				position;
	int				cost;
	int				priority;
	int				stack_size;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	int				max;
	int				min;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

int		ft_check(char **s, int max);
int		ft_mod_atoi(const char *str);
t_stack	*ft_mod_lstnew(int content, t_stack **first);
void	ft_mod_lstadd_back(t_stack **lst, t_stack *new);
void	ft_mod_lstclear(t_stack **lst);
t_stack	*create_stack(char **args, int size, t_stack **head);
void	swap(t_stack *stack);
void	push(t_stack **dest, t_stack **src);
int		ft_mod_lstsize(t_stack *lst);
bool	check_argtype(char *s);
void	r_rotate(t_stack **stack);
void	rotate(t_stack **stack);
int		check_dup(char **s, int max);
int		ft_char_check(char **s, int max);
bool	overflow_check(char *s);
void	put_target(t_stack *stack);
void	rotate_b(t_stack **b);
void	swap_int(int *a, int *b);
void	rotate_a(t_stack **a);
void	clear_node(t_stack **node);
void	push_a(t_stack **a, t_stack **b);
void	swap_both(t_stack **a, t_stack **b);
void	swap_b(t_stack **b);
void	rotate_both(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	r_rotate_b(t_stack **b);
void	r_rotate_a(t_stack **a);
void	r_rotate_both(t_stack **a, t_stack **b);
void	turk_algo(t_stack **a, t_stack **b);
void	set_positon(t_stack *stack);
void	set_value(t_stack *stack);
int		find_borders(int min_or_max, t_stack *stack);
void	find_cost(t_stack *a, t_stack *b);
int		count_rotates(int target, t_stack *stack);
int		inside_interval(int nbr, t_stack *b);
int		sorted(t_stack *first);
char	*my_free(char **str, char **buf);
int		check_dump(int *dump, int size);
void	small_turk_aglo(t_stack **a, t_stack **b);
void	max3_algo(t_stack **a);
void	count_b_rotates(t_stack *temp, int b_rotates);
int		count_b_r_rotates(t_stack *b, t_stack *temp);
void	max5_apply_a_rotates(t_stack **a, t_stack **b, t_stack *temp);
void	max5_inside_borders(t_stack **a, t_stack **b, int nbr, t_stack *temp);
void	max5_reset(t_stack **a);
void	op_2(t_stack **a, t_stack **b, t_stack *optimal);
void	mini_sort(t_stack **a, t_stack **b);
void	small_turk_aglo(t_stack **a, t_stack **b);
int		absolute_value(int nbr);

#endif
