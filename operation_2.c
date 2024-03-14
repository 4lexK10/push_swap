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
	(*a)->min = find_borders(MIN, *a);
	(*a)->max = find_borders(MAX, *a);
	if (*b != NULL)
	{
		(*b)->min = find_borders(MIN, *b);
		(*b)->max = find_borders(MAX, *b);
	}
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
	if (*a != NULL)
	{
		(*a)->min = find_borders(MIN, *a);
		(*a)->max = find_borders(MAX, *a);
	}
	(*b)->min = find_borders(MIN, *b);
	(*b)->max = find_borders(MAX, *b);
	write(1, "pb\n", 3);
}

void	swap_a(t_stack **a)
{
	swap(*a);
	(*a)->stack_size = ft_mod_lstsize(*a);
	set_positon(*a);
	(*a)->min = find_borders(MIN, *a);
	(*a)->max = find_borders(MAX, *a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **b)
{
	swap(*b);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*b);
	(*b)->min = find_borders(MIN, *b);
	(*b)->max = find_borders(MAX, *b);
	write(1, "sb\n", 3);
}

void	rotate_a(t_stack **a)
{
	rotate(a);
	(*a)->stack_size = ft_mod_lstsize(*a);
	set_positon(*a);
	(*a)->min = find_borders(MIN, *a);
	(*a)->max = find_borders(MAX, *a);
	write(1, "ra\n", 3);
}
