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

	if (!stack)
		return ;
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
	t_stack *temp;
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
	while (temp->target != extrema)
		temp = temp->previous;
	temp->priority = 1;
	return (extrema);
}

void	find_cost(t_stack *a, t_stack *b)
{
	t_stack *temp;
	int		size;
	int		current;
/* 	int		i; */

	temp = a;
	size = ft_mod_lstsize(a);
/* 	i = 1; */
	while (size--)
	{
		current = temp->target;
		temp->cost = temp->position + 1;
		if (ft_mod_lstsize(a) < 2 * (temp->position))
			temp->cost = ft_mod_lstsize(a) - temp->position + 1;
		if (!(inside_interval(temp->target, b)))
			temp->cost += ABS(count_rotates(current, b));
		temp = temp->next;
	}
/* 	size = ft_mod_lstsize(a);
	temp = a;
	temp = temp->previous;
	while (size--)
	{
		if (temp->cost > ++i)
			temp->cost = i;
		temp = temp->previous;
	} */
/* 	while (temp != a)
	{
		if (find_borders(MIN, &b) < temp->target && temp->target < find_borders(MAX, &b))
			temp->cost = 0;
		temp = temp->next;
	} */
}
