/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:32:19 by akloster          #+#    #+#             */
/*   Updated: 2024/01/16 16:00:48 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/libftprintf.h"




int main(int ac, char **av)
{
	t_stack	*head;
	t_stack	*curr;

	if (ac <= 1 || ft_check(av, ac))
		return (ft_printf("Error\n"));
	head = create_stack_a(av, ac);
	if (head == NULL)
		return (0);
	curr = head;
	while (--ac > 0)
	{
		ft_printf("%d\n", curr->content);
		curr = curr->next;
	}
	return (ft_mod_lstclear(&head), 0);
}
