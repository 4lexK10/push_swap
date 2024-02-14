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

void	swap(t_stack **stack)
{
	t_stack	*temp;
	
	if (ft_mod_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	push(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*b)
		return ;
	if (!*a)
	{
		*a = *b;
		*b = (*b)->next;
		(*a)->next = NULL;
		return ;
	}
	temp = *b;
	if (temp->next == NULL)
	{
		temp->next = *a;
		*a = temp;
		*b = NULL;
		return ;
	}
	*b = temp->next;
	temp->next = *a;
	*a = temp;
}

void	rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *op;

	if (!*stack || !((*stack)->next))
		return ;
	temp = *stack;
	op = *stack;
	if (temp->next == NULL)
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	(*stack) = (*stack)->next;
	temp->next = op;
	op->next = NULL;
}

void	r_rotate(t_stack **stack)
{
	t_stack *temp;

	if (!*stack || !((*stack)->next))
		return ;
	temp = *stack;
	if (temp->next == NULL)
		return;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
}

/* int main(char **av, int ac)
{
	t_stack *test;
	
	if (ac < 2)
		return (0);
	test = create_stack_a(av, ac);
	swap(test);
	ft_printf("%d, %d\n", test->nbr, test->next->nbr);

	return (0);
} */