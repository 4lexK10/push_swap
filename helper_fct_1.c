/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:47:27 by akloster          #+#    #+#             */
/*   Updated: 2023/10/23 11:28:33 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	overflow(long sign)
{
	if (sign > 0)
		return (-1);
	return (0);
}

int	ft_mod_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;
	int	temp;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		++i;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = nb;
		nb = nb * 10 + str[i++] - '0';
		if (temp > nb && !(nb == INT_MIN && sign == -1))
			return (overflow(sign));
	}
	nb = (nb * sign);
	return (nb);
}

void	ft_mod_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*prev;
	int i;

	i = 0;
	if (!lst || !(*lst))
		return ;
	temp = (*lst)->next;
	prev = temp;
	while (temp != *lst)
	{
		free(temp->previous);
		prev = temp;
		temp = temp->next;
	}
	free(prev);
	*lst = NULL;
}

t_stack	*create_stack(char **args, int size, t_stack **head)
{
	int		i;
	t_stack	*curr;


	i = 1;
	*head = ft_mod_lstnew(ft_atoi(args[i]), head);
	if (!(*head))
		return (NULL);
	while (--size - 1 > 0)
	{
		/* printf("%d test3\n", (*head)->previous->content); */
		curr = ft_mod_lstnew(ft_atoi(args[++i]), head);
		/* printf("2test\n"); */
		if (curr == NULL)
			return (ft_mod_lstclear(head), NULL);
	}
	/* printf("%d test3\n", (*head)->content); */
	return (*head);
}

int	ft_mod_lstsize(t_stack *lst)
{
	t_stack *temp; 
	int	size;

	if (!lst)
		return (0);
	temp = lst->next;
	size = 1;
	while (temp != lst)
	{
		temp = temp->next;
		++size;
	}
	return (size);
}
