/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fct_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:39:23 by akloster          #+#    #+#             */
/*   Updated: 2024/02/20 15:39:23 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_node(t_stack **node)
{
	if (!node || !(*node))
		return ;
	free(*node);
	*node = NULL;
}

void	set_positon(t_stack *stack)
{
	t_stack	*first;
	int		i;

	if (!stack)
		return ;
	first = stack;
	i = 0;
	stack->position = i;
	stack = stack->next;
	while (stack != first)
	{
		stack->position = ++i;
		stack = stack->next;
	}
}

void	set_value(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*current;
	int		count;
	int		i;
	int		j;

	i = ft_mod_lstsize(stack) + 1;
	j = ft_mod_lstsize(stack) + 1;
	current = stack;
	temp = stack;
	count = 0;
	while (--i)
	{
		while (--j)
		{
			if (temp != current && temp->content < current->content)
				++count;
			temp = temp->next;
		}
		j = ft_mod_lstsize(stack) + 1;
		current->value = count;
		count = 0;
		current = current->next;
	}
}

int	find_borders(int min_or_max, t_stack *stack)
{
	t_stack	*temp;
	int		extrema;

	temp = stack;
	extrema = temp->target;
	temp = temp->next;
	while (temp != stack)
	{
		if (min_or_max == MAX && extrema < temp->target)
			extrema = temp->target;
		if (min_or_max == MIN && extrema > temp->target)
			extrema = temp->target;
		temp = temp->next;
	}
	return (extrema);
}

void	find_cost(t_stack *a, t_stack *b)
{
	t_stack	*temp;
	int		size;

	temp = a;
	size = a->stack_size;
	while (size--)
	{
		temp->ra = 0;
		temp->rra = 0;
		temp->rb = 0;
		temp->rrb = 0;
		temp->cost = temp->position + 1;
		if (a->stack_size < 2 * (temp->position))
		{
			temp->cost = a->stack_size - temp->position + 1;
			temp->rra = a->stack_size - temp->position;
		}
		else
			temp->ra = temp->position;
		if (!(inside_interval(temp->target, b)))
			count_b_rotates(temp, count_rotates(temp->target, b));
		temp = temp->next;
	}
}
