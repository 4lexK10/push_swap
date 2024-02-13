/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:32:19 by akloster          #+#    #+#             */
/*   Updated: 2024/02/05 11:39:05 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*curr_a;
	t_stack	*curr_b;
	int		i;
	
	i = 0;
	if (ft_check(av, ac) == 2)
	{
		av = ft_split(ft_strjoin("./pushswap ", av[1]), ' ');
		while (av[i] != NULL)
			++i;
		ac = i;
	}
	if (ft_check(av, ac) == 1)
		return (ft_printf("Error\n"));
	head_a = create_stack(av, ac);
	head_b = create_stack(av, ac);
/* 	push(&head, &head_b);
	push(&head, &head_b);
	push(&head, &head_b);
	r_rotate(&head);
	rotate(&head_b); */
	put_order(&head_a);
	put_order(&head_b);
	curr_a = head_a;
	curr_b = head_b;
	ft_printf("stack a\n");
	while (curr_a != NULL)
	{
		ft_printf("content: %d", curr_a->content);
		ft_printf(" nbr:%d\n", curr_a->nbr);
		curr_a = curr_a->next;
	}
	ft_printf("stack b\n");
	while (curr_b != NULL)
	{
		ft_printf("content: %d", curr_b->content);
		ft_printf(" nbr:%d\n", curr_b->nbr);
		curr_b = curr_b->next;
	}
	return (ft_mod_lstclear(&head_a), ft_mod_lstclear(&head_b), 0);
}
