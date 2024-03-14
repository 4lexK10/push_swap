/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:52:25 by akloster          #+#    #+#             */
/*   Updated: 2024/03/11 18:59:53 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_turk_aglo(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		nbr;

	push_b(a, b);
	push_b(a, b);
	max3_algo(a);
	while (*b != NULL)
	{
		nbr = (*b)->target;
		temp = *a;
		if (nbr < find_borders(MIN, *a))
			max5_apply_a_rotates(a, b, temp);
		else if (nbr > find_borders(MAX, *a))
		{
			max5_apply_a_rotates(a, b, temp);
			rotate_a(a);
		}
		else
			max5_inside_borders(a, b, nbr, temp);
	}
	max5_reset(a);
}

int	absolute_value(int nbr)
{
	if (nbr >= 0)
		return (nbr);
	return (-nbr);
}
