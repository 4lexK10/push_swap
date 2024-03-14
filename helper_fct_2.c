/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fct_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:40:11 by akloster          #+#    #+#             */
/*   Updated: 2024/02/05 12:27:34 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_argtype(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		++i;
	if (s[i] == '\0')
		return (0);
	if (s[i] >= '0' && s[i] <= '9' && s[i + 1] == '\0')
		return (1);
	--i;
	while (s[++i] != '\0')
	{
		if (s[i] == ' ')
			return (1);
	}
	return (0);
}

int	check_dup(char **s, int size)
{
	int		*dump;
	int		i;
	int		j;

	i = -1;
	j = 1;
	dump = ft_calloc(size - 1, 4);
	if (!dump)
		return (1);
	while (++i < size - 1)
		dump[i] = ft_mod_atoi(s[i + j]);
	return (check_dump(dump, size));
}

int	ft_char_check(char **s, int max)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	while (i < max)
	{
		if (!s[i] || s[i][0] == '\0')
			return (1);
		if (s[i][0] == '-')
			if (s[i][++j + 1] == '\0')
				return (1);
		while (s[i][++j] != '\0')
			if (s[i][j] < '0' || s[i][j] > '9')
				return (1);
		if (overflow_check(s[i]))
			return (1);
		++i;
		j = -1;
	}
	return (0);
}

void	put_target(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*current;
	int		count;
	int		i;
	int		j;

	i = ft_mod_lstsize(stack) + 1;
	j = ft_mod_lstsize(stack) + 1;
	current = stack;
	temp = stack;
	count = 0;
	while (--i)
	{
		while (--j)
		{
			if (temp != current && temp->content < current->content)
				++count;
			temp = temp->next;
		}
		j = ft_mod_lstsize(stack) + 1;
		current->target = count;
		count = 0;
		current = current->next;
	}
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
