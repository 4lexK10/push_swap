/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:54:48 by akloster          #+#    #+#             */
/*   Updated: 2024/03/04 19:49:27 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	if (*a)
		(*a)->stack_size = ft_mod_lstsize(*a);
	if (*b)
		(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	push(b, a);
	if (*a)
		(*a)->stack_size = ft_mod_lstsize(*a);
	if (*b)
		(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "pb\n", 3);
}

void	swap_a(t_stack **a)
{
	swap(*a);
	(*a)->stack_size = ft_mod_lstsize(*a);
	set_positon(*a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	swap(*b);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*b);
	write(1, "sb\n", 3);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	(*a)->stack_size = ft_mod_lstsize(*a);
	(*b)->stack_size = ft_mod_lstsize(*b);;
	set_positon(*a);
	set_positon(*b);
	write(1, "ss\n", 3);
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	(*a)->stack_size = ft_mod_lstsize(*a);
	set_positon(*a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);  
	rotate(b);
	(*a)->stack_size = ft_mod_lstsize(*a);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "rr\n", 3);
}

void	r_rotate_a(t_stack **a)
{
	r_rotate(a);
	(*a)->stack_size = ft_mod_lstsize(*a);
	set_positon(*a);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **b)
{
	r_rotate(b);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*b);
	write(1, "rrb\n", 4);
}

void	r_rotate_both(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	(*a)->stack_size = ft_mod_lstsize(*a);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "rrr\n", 4);
}