/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fct_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:49:55 by akloster          #+#    #+#             */
/*   Updated: 2024/03/11 18:49:55 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	inside_interval_variable(int nbr, t_stack *stack, t_stack *b)
{
	int	max;

	max = b->max;
	if (nbr > max && stack->target == max)
		return (1);
	if (nbr < b->min && stack->target == max)
		return (1);
	if (nbr > stack->target && nbr < stack->previous->target)
		return (1);
	return (0);
}

int	count_rotates(int nbr, t_stack *b)
{
	t_stack	*temp;
	t_stack	*target_node;
	int		cnt;
	int		r_cnt;

	temp = b;
	cnt = 0;
	r_cnt = 0;
	if (inside_interval(nbr, b) == 1)
		return (0);
	while (inside_interval_variable(nbr, temp, b) == 0)
		temp = temp->next;
	target_node = temp;
	while (temp != b)
	{
		++cnt;
		temp = temp->previous;
	}
	temp = target_node;
	r_cnt = count_b_r_rotates(b, temp);
	if (r_cnt < cnt)
		return (-r_cnt);
	return (cnt);
}

int	inside_interval(int nbr, t_stack *stack)
{
	int	max;

	max = stack->max;
	if (nbr > max && stack->target == max)
		return (1);
	if (nbr < stack->min && stack->target == max)
		return (1);
	if (nbr > stack->target && nbr < stack->previous->target)
		return (1);
	return (0);
}

char	*my_free(char **str, char **buf)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}

int	check_dump(int *dump, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		temp = dump[i];
		while (j < size - 1)
		{
			if (dump[j] == temp && j != i)
				return (free(dump), 1);
			++j;
		}
		j = 0;
		++i;
	}
	return (free(dump), 0);
}
