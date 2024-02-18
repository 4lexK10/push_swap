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

typedef struct s_stack
{
	int				nbr;
	int				content;
	int				cost;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

int		ft_check(char **s, int max);
int		ft_mod_atoi(const char *str);
t_stack	*ft_mod_lstnew(int content, t_stack **first);
void	ft_mod_lstadd_back(t_stack **lst, t_stack *new);
void	ft_mod_lstclear(t_stack **lst);
t_stack	*create_stack(char **args, int size, t_stack **head);
void	swap(t_stack **stack);
void	push(t_stack **a, t_stack **b);
int		ft_mod_lstsize(t_stack *lst);
bool	check_argtype(char *s);
void	r_rotate(t_stack **stack);
void	rotate(t_stack **stack);
int		check_dup(char **s, int max);
int		ft_char_check(char **s, int max);
bool	overflow_check(char *s);
void	put_order(t_stack *stack);

#endif
