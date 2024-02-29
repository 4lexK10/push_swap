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
	size = ft_mod_lstsize(stack);
	while (size--)
	{
		if (first->target < temp->next->target)
			first = temp->next;
		temp = temp->next;
	}
	size = ft_mod_lstsize(stack);
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
	if ((*b)->value == 0 && (*b)->previous->value == 2)
	{
		swap_b(b);
		r_rotate_b(b);
	}
	if ((*b)->value == 0 && (*b)->previous->value == 1)
		rotate_b(b);
	if ((*b)->value == 1 && (*b)->previous->value == 2)
		r_rotate_b(b);
	if ((*b)->value == 1 && (*b)->previous->value == 0)
		swap_b(b);
	if ((*b)->value == 2 && (*b)->previous->value == 1)
	{	
		swap_b(b);
		rotate_b(b);
	}
}

static	void	max3_algo(t_stack **a)
{
	if (!a || !(*a))
		return ;
	if ((*a)->next == *a)
		return ;
	if (ft_mod_lstsize(*a) == 2)
		rotate_a(a);
	if (ft_mod_lstsize(*a) == 3)
	{
		if ((*a)->value == 0 && (*a)->previous->value == 1)
		{
			swap_a(a);
			rotate_a(a);
		}
		if ((*a)->value == 1 && (*a)->previous->value == 2)
			swap_a(a);
		if ((*a)->value == 1 && (*a)->previous->value == 0)
			r_rotate_a(a);
		if ((*a)->value == 2 && (*a)->previous->value == 0)
		{	
			swap_a(a);
			r_rotate_a(a);
		}
		if ((*a)->value == 2 && (*a)->previous->value == 1)
			r_rotate_a(a);
	}
}

static void	run_operations(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack *optimal;
	int		size;

	temp = *a;
	optimal = temp;
	size = ft_mod_lstsize(*a);
	if (optimal->cost == 1)
	{
		push_b(a, b);
		return ;
	}
	while(--size)
	{
		temp = temp->next;
		if (temp->cost < optimal->cost)
			optimal = temp;
	}
	if (optimal == *a)
	{
		size = count_rotates(optimal->target, *b);
		/* printf("rb to do%d\n", size); */
		if (size < 0)
		{
			size = -size;
			while (size--)
				r_rotate_b(b);
		}
		if (size > 0)
		{
			while (size--)
				rotate_b(b);
		}
		push_b(a, b);
		return ;
	}
	size = ft_mod_lstsize(*a) - optimal->position;
	if (ft_mod_lstsize(*a) < 2 * (optimal->position))
		while (size-- > 0)
			r_rotate_a(a);
	else
	{
		size = optimal->position;
		while (size-- > 0)
			rotate_a(a);
	}
	size = count_rotates(optimal->target, *b);
	if (size > 0)
	{
		while (size-- > 0)
			rotate_b(b);
	}
	else if (size < 0)
	{
		while (size++ < 0)
			r_rotate_b(b);
	}
	push_b(a, b);
}

void	turk_algo(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (ft_mod_lstsize(*a) <= 3)
	{
		max3_algo(a);
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
	if (temp->position <= ft_mod_lstsize(*a) / 2)
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
