/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:54:48 by akloster          #+#    #+#             */
/*   Updated: 2024/02/20 18:46:41 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	push_b(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
}

void	swap_a(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");    
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a);  
	rotate(b);
	ft_printf("rr\n"); 
}

void	r_rotate_a(t_stack **a)
{
	r_rotate(a);
	ft_printf("rra\n");
}

void	r_rotate_b(t_stack **b)
{
	r_rotate(b);
	ft_printf("rrb\n");
}

void	r_rotate_both(t_stack **a, t_stack **b)
{
	r_rotate(a);
	r_rotate(b);
	ft_printf("rrr\n");
}