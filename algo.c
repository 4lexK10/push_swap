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

static	int	sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (a->target == i++)
		a = a->next;
	if (i != 0 && a->target == 0)
		return (1);
	return (0);
}

void	max3_algo(t_stack **a)
{
	if (!a || !(*a))
		return ;
	printf("test\n");
	if ((*a)->next == *a)
		return ;
	if (sorted(*a))
		return ;
	if (ft_mod_lstsize(*a) == 2)
		rotate_a(a);
	if (ft_mod_lstsize(*a) == 3)
	{
		if ((*a)->target == 0 && (*a)->previous->target == 1)
		{
			swap_a(a);
			rotate_a(a);
		}
		if ((*a)->target == 1 && (*a)->previous->target == 2)
			swap_a(a);
		if ((*a)->target == 1 && (*a)->previous->target == 0)
			r_rotate_a(a);
		printf("test11\n");
		if ((*a)->target == 2 && (*a)->previous->target == 0)
		{	
			swap_a(a);
			r_rotate_a(a);
		}
		if ((*a)->target == 2 && (*a)->previous->target == 1)
			r_rotate_a(a);
	}
}

void	turk_algo(t_stack **a, t_stack **b)
{
/* 	if (ft_mod_lstsize(*a) < 4 && *a)
		return (max3_algo(a));
	if (ft_mod_lstsize(*b) < 4 && *b)
		return (max3_algo(b)); */
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
/* 	printf("%d\n", ft_mod_lstsize(*b)); */
	max3_algo(a);
}