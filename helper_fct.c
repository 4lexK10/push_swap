#include "push_swap.h"
static bool	overflow_check(char *s)
{
	int	res;

	res = ft_atoi(s);
	if (res == 0 && s[0] != 0)
		return (1);
	if (res == -1 && s[1] != '\0')
		return (1);
	return (0);
}

bool	ft_check(char **s, int max)
{
        int	i;
	int     j;

	i = 1;
	j = -1;
	if (!s)
		return (1);
	while (i < max)
	{
		if (!s[i] || s[i][0] == '\0')
			return (1);
		if (s[i][0] == -1)
			++j;
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
