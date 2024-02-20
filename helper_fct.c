/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akloster <akloster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:47:35 by akloster          #+#    #+#             */
/*   Updated: 2024/02/05 11:47:38 by akloster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool real_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		++i;
	while (s[i] != '\0' && s[i] == '0')
		++i;
	if (s[i] == '\0' || (s[i] == '1' && s[i + 1] == '\0'))
		return (0);
	return (1);
}

bool	overflow_check(char *s)
{
	int	res;

	res = ft_mod_atoi(s);
	if (res == 0 && real_check(s))
		return (1);
	if (res == -1 && real_check(s))
		return (1);
	return (0);
}

int		ft_check(char **s, int max)
{
	if (max == 1)
		return (3);
	if (!(*s) || max < 2 || check_dup(s, max))
		return (1);
	if (s[1] && check_argtype(s[1]))
		return (2);
	return (ft_char_check(s, max));
}

t_stack	*ft_mod_lstnew(int content, t_stack **head)
{
	t_stack	*new_node;
/* 	int i;

	i = 0; */
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	if (*head == NULL)
		*head = new_node;
	new_node->content = content;
	new_node->target = 0;
	new_node->cost = 0;
	new_node->next = *head;
	if (*head != new_node)
	{
		new_node->previous = (*head)->previous;
		(*head)->previous->next = new_node;
		(*head)->previous = new_node;
	}
	else 
		new_node->previous = *head;
/* 	printf("%d->node #%d\n", new_node->content, ++i); */
	return (new_node);
}

void	ft_mod_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new || !lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
