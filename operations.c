/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:59:02 by akloster          #+#    #+#             */
/*   Updated: 2024/02/05 11:41:26 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	if (ft_mod_lstsize(stack) < 2)
		return ;
	swap_int(&(stack->content), &(stack->next->content));
	swap_int(&(stack->cost), &(stack->next->cost));
	swap_int(&(stack->target), &(stack->next->target));
}

static	void	finish_push(t_stack **dest, t_stack **src)
{
	t_stack	*temp;

	temp = *src;
	*src = (*src)->next;
	if (*src == (*src)->next)
		*src = NULL;
	else
	{
		temp->next->previous = temp->previous;
		temp->previous->next = temp->next;
	}
	temp->next = *dest;
	temp->previous = (*dest)->previous;
	(*dest)->previous->next = temp;
	(*dest)->previous = temp;
	*dest = temp;
}

void	push(t_stack **dest, t_stack **src)
{
	if (!*src)
		return ;
	if (!*dest)
	{
		if (*src == (*src)->next)
		{
			*dest = *src;
			*src = NULL;
			return ;
		}
		(*src)->next->previous = (*src)->previous;
		(*src)->previous->next = (*src)->next;
		*dest = *src;
		*src = (*src)->next;
		(*dest)->next = *dest;
		(*dest)->previous = *dest;
		return ;
	}
	finish_push(dest, src);
}

void	rotate(t_stack **stack)
{
	if (!(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	r_rotate(t_stack **stack)
{
	if (!(*stack) || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->previous;
}
