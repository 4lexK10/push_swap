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

static	int	sorted(t_stack *first)
{
	t_stack	*temp;
	int	size;
	int	i;

	temp = first;
	size = ft_mod_lstsize(first);
	i = 0;
	if (!first)
		return (0);
	if (temp->next == first)
		return (1);
	while (temp->target == i++)
		temp = temp->next;
	if (temp == first && i == size)
		return (1);
	temp = first->previous;
	i = size - 1;
	while (temp->value == i--)
		temp = temp->previous;
	if (temp == first->previous && i == -1)
		return (1);
	return (0);
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
	if (sorted(*a))
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
		printf("rb to do%d\n", size);
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
	if (sorted(*a))
		return ;
	if (ft_mod_lstsize(*a) <= 3)
	{
		max3_algo(a);
		return ;
	}
	set_start(a, b);
	while (*a != NULL)
	{
		find_cost(*a, *b);
		/*rint_stacks(*a, *b);*/
		run_operations(a, b);
		while ((*b)->target < find_borders(MAX, b))
			rotate_b(b);
	}
/* 	while (*b != NULL)
		push_a(a, b); */
}
