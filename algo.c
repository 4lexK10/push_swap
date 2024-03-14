/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:47:22 by akloster          #+#    #+#             */
/*   Updated: 2024/02/05 12:32:00 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack *stack)
{
	t_stack	*temp;
	int		size;

	temp = stack;
	size = stack->stack_size;
	while (--size)
	{
		if (temp->target < temp->next->target)
			temp = temp->next;
	}
	if (temp->next == stack)
		return (1);
	return (0);
}

static void	set_start(t_stack **a, t_stack **b)
{
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	set_value(*b);
	if ((*b)->value == 0 && (*b)->previous->value == 2)
	{
		swap_b(b);
		r_rotate_b(b);
	}
	else if ((*b)->value == 0 && (*b)->previous->value == 1)
		rotate_b(b);
	else if ((*b)->value == 1 && (*b)->previous->value == 2)
		r_rotate_b(b);
	else if ((*b)->value == 1 && (*b)->previous->value == 0)
		swap_b(b);
	else if ((*b)->value == 2 && (*b)->previous->value == 1)
	{
		swap_b(b);
		rotate_b(b);
	}
}

void	max3_algo(t_stack **a)
{
	set_value(*a);
	if ((*a)->next == *a)
		return ;
	if (ft_mod_lstsize(*a) == 2 && (*a)->target > (*a)->next->target)
		rotate_a(a);
	if (ft_mod_lstsize(*a) == 3)
	{
		if ((*a)->value == 0 && (*a)->previous->value == 1)
		{
			swap_a(a);
			rotate_a(a);
		}
		else if ((*a)->value == 1 && (*a)->previous->value == 2)
			swap_a(a);
		else if ((*a)->value == 1 && (*a)->previous->value == 0)
			r_rotate_a(a);
		else if ((*a)->value == 2 && (*a)->previous->value == 0)
		{
			swap_a(a);
			r_rotate_a(a);
		}
		else if ((*a)->value == 2 && (*a)->previous->value == 1)
			rotate_a(a);
	}
}

static void	run_operations(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*optimal;
	int		size;
	int		i;

	temp = *a;
	optimal = temp;
	size = (*a)->stack_size;
	if (optimal->cost == 1)
	{
		push_b(a, b);
		return ;
	}
	i = size;
	while (--i)
	{
		temp = temp->next;
		if (temp->cost < optimal->cost)
			optimal = temp;
	}
	op_2(a, b, optimal);
}

void	turk_algo(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (sorted(*a) || ft_mod_lstsize(*a) <= 5)
	{
		mini_sort(a, b);
		return ;
	}
	set_start(a, b);
	while (*a != NULL)
	{
		find_cost(*a, *b);
		run_operations(a, b);
	}
	while (*b != NULL)
		push_a(a, b);
	temp = *a;
	while (temp->target != find_borders(MIN, *a))
		temp = temp->next;
	if (temp->position <= (*a)->stack_size / 2 && (*a)->target != 0)
		while (temp != *a)
			rotate_a(a);
	else
		while (temp != *a)
			r_rotate_a(a);
}
