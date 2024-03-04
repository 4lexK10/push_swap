/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:54:48 by akloster          #+#    #+#             */
/*   Updated: 2024/03/01 14:45:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	set_value(*a);
	set_value(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	push(b, a);
	set_value(*a);
	set_value(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "pb\n", 3);
}

void	swap_a(t_stack **a)
{
	swap(*a);
	set_value(*a);
	set_positon(*a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	swap(*b);
	set_value(*b);
	set_positon(*b);
	write(1, "sb\n", 3);
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	set_value(*a);
	set_value(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "ss\n", 3);
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	set_value(*a);
	set_positon(*a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	set_value(*b);
	set_positon(*b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);  
	rotate(b);
	set_value(*a);
	set_value(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "rr\n", 3);
}

void	r_rotate_a(t_stack **a)
{
	r_rotate(a);
	set_value(*a);
	set_positon(*a);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **b)
{
	r_rotate(b);
	set_value(*b);
	set_positon(*b);
	write(1, "rrb\n", 4);
}

void	r_rotate_both(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	set_value(*a);
	set_value(*b);
	set_positon(*a);
	set_positon(*b);
	write(1, "rrr\n", 4);
}