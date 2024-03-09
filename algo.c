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
	t_stack *first;
	int		size;

	temp = stack;
	first = stack;
	size = stack->stack_size;
	while (size--)
	{
		if (first->target < temp->next->target)
			first = temp->next;
		temp = temp->next;
	}
	size = stack->stack_size;
	temp = first;
	while (--size)
	{
		if (temp->next->target > temp->target)
			return (0);
		temp = temp->next;
	}
	return (1);
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
	t_stack *optimal;
	int		size;
	int		rotates;
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
	while(--i)
	{
		temp = temp->next;
		if (temp->cost < optimal->cost)
			optimal = temp;
	}
	if (optimal == *a)
	{
		if (optimal->rb > 0)
		{
			rotates = optimal->rb;
			while (rotates--)
				rotate_b(b);
			optimal->rb = 0;
		}
		else if (optimal->rrb > 0)
		{
			rotates = optimal->rrb;
			while (rotates--)
				r_rotate_b(b);
			optimal->rrb = 0;
		}
		push_b(a, b);
		return ;
	}
	if (optimal->ra > 0)
	{
		rotates = optimal->ra;
		while (rotates--)
			rotate_a(a);
		optimal->ra = 0;
	}
	if (optimal->rra > 0)
	{
		rotates = optimal->rra;
		while (rotates--)
			r_rotate_a(a);
		optimal->rra = 0;
	}
	if (optimal->rb > 0)
	{
		rotates = optimal->rb;
		while (rotates--)
			rotate_b(b);
		optimal->rb = 0;
	}
	if (optimal->rrb > 0)
	{
		rotates = optimal->rrb;
		while (rotates--)
			r_rotate_b(b);
		optimal->rrb = 0;
	}
	push_b(a, b);
}

void	turk_algo(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		min;

	if (ft_mod_lstsize(*a) <= 3)
		max3_algo(a);
	if (ft_mod_lstsize(*a) == 5)
		small_turk_aglo(a, b);
	else 
	{
		set_start(a, b);
		while (*a != NULL)
		{
			find_cost(*a, *b);
			/* print_stacks(*a, *b); */
			run_operations(a, b);
		}
		while (*b != NULL)
			push_a(a, b);
	}
	temp = *a;
	min = find_borders(MIN, *a);
	while (temp->target != min)
		temp = temp->next;
	if (temp->position <= (*a)->stack_size / 2 && (*a)->target != 0)
	{
		while (temp != *a)
			rotate_a(a);
	}
	else
	{
		while (temp != *a)
			r_rotate_a(a);
	}
}
