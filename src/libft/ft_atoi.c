#include "libft.h"

int	ft_atoi(const char *str)
{
	int	x;
	int	i;
	int	sign;

	x = 0;
	i = 0;
	sign = 1;
	while (str[i] == 9 || str[i] == 32 || str[i] == 10 || str[i] == 11
		|| str[i] == 12 || str[i] == 13)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
		x = x * 10 + str[i++] - '0';
	return (x * sign);
}
