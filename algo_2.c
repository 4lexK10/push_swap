/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:17:48 by akloster          #+#    #+#             */
/*   Updated: 2024/03/11 18:43:37 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rb_opti(t_stack **b, t_stack *optimal)
{
	int	rotates;

	rotates = optimal->rb;
	while (rotates--)
		rotate_b(b);
	optimal->rb = 0;
}

static	void	rrb_opti(t_stack **b, t_stack *optimal)
{
	int	rotates;

	rotates = optimal->rrb;
	while (rotates--)
		r_rotate_b(b);
	optimal->rrb = 0;
}

static	void	ra_opti(t_stack **a, t_stack *optimal)
{
	int	rotates;

	rotates = optimal->ra;
	while (rotates--)
		rotate_a(a);
	optimal->ra = 0;
}

void	op_2(t_stack **a, t_stack **b, t_stack *optimal)
{
	int	rotates;

	if (optimal == *a)
	{
		if (optimal->rb > 0)
			rb_opti(b, optimal);
		else if (optimal->rrb > 0)
			rrb_opti(b, optimal);
		push_b(a, b);
		return ;
	}
	if (optimal->ra > 0)
		ra_opti(a, optimal);
	if (optimal->rra > 0)
	{
		rotates = optimal->rra;
		while (rotates--)
			r_rotate_a(a);
		optimal->rra = 0;
	}
	if (optimal->rb > 0)
		rb_opti(b, optimal);
	if (optimal->rrb > 0)
		rrb_opti(b, optimal);
	push_b(a, b);
}

void	mini_sort(t_stack **a, t_stack **b)
{
	if (sorted(*a))
		return ;
	if (ft_mod_lstsize(*a) <= 3)
		max3_algo(a);
	else if (ft_mod_lstsize(*a) <= 5)
		small_turk_aglo(a, b);
}
