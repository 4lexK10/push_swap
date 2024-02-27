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

# include <stdio.h> //  <----- TAKE OUT!!!
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "ft_printf/libftprintf.h"
# include "libft/libft.h"
# define ABS(Value)     Value * ((Value > 0) - (Value < 0))
# define MAX 1
# define MIN -1

typedef struct s_stack
{
	int				target;
	int				value;
	int				content;
	int				position;
	int				cost;
	int 			priority;
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
void    clear_node(t_stack **node);
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
int		find_borders(int min_or_max, t_stack **stack);
void	find_cost(t_stack *a, t_stack *b);
void    print_stacks(t_stack *a, t_stack *b);
int		count_rotates(int target, t_stack *stack);

#endif
