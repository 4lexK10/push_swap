#include "push_swap.h"

int count_rotates(int nbr, t_stack *b)
{
	t_stack *temp;
	t_stack *target_node;
	int	cnt;
	int	r_cnt;

	temp = b;
	cnt = 0;
	r_cnt = 0;
	if (inside_interval(nbr, b) == 1)
		return (0);
	while (inside_interval(nbr, temp) == 0)
		temp = temp->next;
	target_node = temp;
	while (temp != b)
	{
		++cnt;
		temp = temp->previous;
	}
	temp = target_node;
	while (temp != b)
	{
		++r_cnt;
		temp = temp->next;
	}
	if (r_cnt < cnt)
		return (-r_cnt);
	return (cnt);
}

int	inside_interval(int nbr, t_stack *b)
{
	int max;

	max = find_borders(MAX, b);
	if (nbr > max && b->target == max)
		return (1);
	if (nbr < find_borders(MIN, b) && b->target == max)
		return (1);
	if (nbr > b->target && nbr < b->previous->target)
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
