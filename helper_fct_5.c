/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fct_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:27:58 by akloster          #+#    #+#             */
/*   Updated: 2024/03/11 18:57:53 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_b_rotates(t_stack *temp, int b_rotates)
{
	temp->cost += absolute_value(b_rotates);
	if (b_rotates < 0)
		temp->rrb = -b_rotates;
	if (b_rotates > 0)
		temp->rb = b_rotates;
}

int	count_b_r_rotates(t_stack *b, t_stack *temp)
{
	int	r_cnt;

	r_cnt = 0;
	while (temp != b)
	{
		++r_cnt;
		temp = temp->next;
	}
	return (r_cnt);
}

void	max5_apply_a_rotates(t_stack **a, t_stack **b, t_stack *temp)
{
	while (temp->target != find_borders(MIN, *a))
		temp = temp->next;
	if (temp->position > ft_mod_lstsize(*a) / 2)
		r_rotate_a(a);
	else
	{
		while (temp != *a)
			rotate_a(a);
	}
	push_a(a, b);
}

void	max5_inside_borders(t_stack **a, t_stack **b, int nbr, t_stack *temp)
{
	while (!(nbr < temp->target && nbr > temp->previous->target))
		temp = temp->next;
	if (temp->position > ft_mod_lstsize(*a) / 2)
		r_rotate_a(a);
	else
		while (temp != *a)
			rotate_a(a);
	push_a(a, b);
}

void	max5_reset(t_stack **a)
{
	if ((*a)->target <= 2)
		while ((*a)->target != 0)
			rotate_a(a);
	else
		while ((*a)->target != 0)
			r_rotate_a(a);
}
