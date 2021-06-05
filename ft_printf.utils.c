#include "printf.h"
void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (fd >= 0)
		{
			while (s[i] != '\0')
			{
				write(fd, &s[i], 1);
				i++;
			}
		}
	}
}
void	ft_putnbr_fd(int n, int fd)
{
	int		num;
	char	s[10];

	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	num = 0;
	while (n > 0)
	{
		s[num] = n % 10 + '0';
		n = n / 10;
		num++;
	}
	num--;
	while (num >= 0)
	{
		ft_putchar_fd(s[num], fd);
		num--;
	}
}

