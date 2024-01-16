#include "push_swap.h"
#include <stdbool.h>

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

static bool	overflow_check(char *s)
{
	int	res;

	res = ft_mod_atoi(s);
	if (res == 0 && real_check(s))
		return (1);
	if (res == -1 && real_check(s))
		return (1);
	return (0);
}

bool	ft_check(char **s, int max)
{
    int	i;
	int	j;

	i = 1;
	j = -1;
	if (!s)
		return (1);
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

t_stack	*ft_mod_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
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
