/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:06:12 by akloster          #+#    #+#             */
/*   Updated: 2024/03/11 17:06:46 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_stack **b)
{
	rotate(b);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*b);
	(*b)->min = find_borders(MIN, *b);
	(*b)->max = find_borders(MAX, *b);
	write(1, "rb\n", 3);
}

void	r_rotate_a(t_stack **a)
{
	r_rotate(a);
	(*a)->stack_size = ft_mod_lstsize(*a);
	set_positon(*a);
	(*a)->min = find_borders(MIN, *a);
	(*a)->max = find_borders(MAX, *a);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_stack **b)
{
	r_rotate(b);
	(*b)->stack_size = ft_mod_lstsize(*b);
	set_positon(*b);
	(*b)->min = find_borders(MIN, *b);
	(*b)->max = find_borders(MAX, *b);
	write(1, "rrb\n", 4);
}
