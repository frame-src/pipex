#include "libft.h"

static void	slice(int n, int fd)
{
	char	temp;

	if (n < 10)
	{
		temp = n + '0';
		write(fd, &temp, 1);
	}
	else
	{
		slice((n / 10), fd);
		temp = n % 10 + '0';
		write(fd, &temp, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		slice(n, fd);
	}
	else
		slice(n, fd);
}
