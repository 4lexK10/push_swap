#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "ft_printf/libftprintf.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

bool	ft_check(char **s, int max);
int		ft_mod_atoi(const char *str);
t_stack	*ft_mod_lstnew(int content);
void	ft_mod_lstadd_back(t_stack **lst, t_stack *new);
void	ft_mod_lstclear(t_stack **lst);
t_stack	*create_stack_a(char **args, int size);

#endif
