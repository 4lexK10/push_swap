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
/* 	printf("%d\n", ft_check(av, ac)); */
	if (ft_check(av, ac) == 3)
		return (0);
	if (ft_check(av, ac) == 2)
	{
		av = ft_split(ft_strjoin("./pushswap ", av[1]), ' ');
		while (av[i] != NULL)
			++i;
		ac = i;
	}
	if (ft_check(av, ac) == 1)
		return (ft_printf("Error\n"));
	head_a = NULL;
	head_b = NULL;
	head_a = create_stack(av, ac, &head_a);
	/* printf("%d\n", head_a->content); */
	printf("%d %d\n", head_a->content, head_a->next->content);
	push(&head_b, &head_a);
	push(&head_b, &head_a);
	push(&head_b, &head_a);
	push(&head_b, &head_a);
	push(&head_b, &head_a);
	push(&head_b, &head_a);
	push(&head_b, &head_a);
/* 	printf("%d %d\n", head_a->content, head_a->next->content); */
/* 	swap(head_a);
	swap(head_b);
	rotate(&head_b); */
	put_order(head_a, ac);
	put_order(head_b, ac);
	curr_a = head_a;
	curr_b = head_b;
	printf("stack a\n");
	if (head_a)
	{
		printf("content:%d", curr_a->content);
		printf(" nbr:%d\n", curr_a->nbr);
		curr_a = curr_a->next;
		while (curr_a != head_a)
		{
			printf("content:%d", curr_a->content);
			printf(" nbr:%d\n", curr_a->nbr);
			curr_a = curr_a->next;
		}
	}
	printf("stack b\n");
	if (head_b)
	{
		printf("content: %d", curr_b->content);
		printf(" nbr:%d\n", curr_b->nbr);
		curr_b = curr_b->next;
		while (curr_b != head_b)
		{
			printf("content: %d", curr_b->content);
			printf(" nbr:%d\n", curr_b->nbr);
			curr_b = curr_b->next;
		}
	}
	return (ft_mod_lstclear(&head_a), ft_mod_lstclear(&head_b), 0);
}
