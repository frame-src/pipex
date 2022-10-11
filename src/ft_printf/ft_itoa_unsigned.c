#include "ft_printf.h"

static int	nlen(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	logic(unsigned int n, char *result, int len)
{
	char	temp;

	if (n == 0)
		result[0] = '0';
	while (n > 0)
	{
		temp = (char )(n % 10) + '0';
		result[(len--) - 1] = temp;
		n = n / 10;
	}
}

char	*ft_itoa_unsigned(unsigned int n)
{
	int		len;
	char	*result;

	len = nlen(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	else if (n == 4294967295)
	{
		n = n - 1;
		logic(n, result, len);
		result[len - 1] = '5';
	}
	else
		logic(n, result, len);
	result[len] = '\0';
	return (result);
}
