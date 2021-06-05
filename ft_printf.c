#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"
int	ft_atoi(const char *str)
{
	int				i;
	int				min;
	unsigned int	res;
	char			*p;

	p = (char *) str;
	i = 0;
	min = 1;
	res = 0;
	while ((p[i] >= 0x09 && p[i] <= 0x0D) || (p[i] == ' '))
		i++;
	if (p[i] == '-')
		min *= -1;
	if (p[i] == '-' || p[i] == '+')
		i++;
	while (p[i] >= '0' && p[i] <= '9')
	{
		res = (res * 10) + (p[i] - '0');
		i++;
	}
	if (res > 2147483648 && min == -1)
		return (0);
	if (res > INT_MAX && min == 1)
		return (-1);
	return (min * res);
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
// typedef struct flags 
// {
//     int width;
//     int minus;
//     int zero;
//     int dot;
//     int digit;

// }   t_flag;
void ft_list_flag(t_flag *flags)
{
    flags -> width = 0;
    flags -> dot = 0;
    flags -> minus = 0;
    flags -> zero = 0;
    flags -> digit = 0;
    flags -> minus = 0;
}
// void ft_process_c(char **name)
// {
//     write(1, &name, 1);
// }
// void ft_process_s(const char **s, va_list name, int i, t_flag *flags)
// {
//     char *ptr;

//     ptr = va_arg(name, char *);
//     while (ptr[i] != '\0' && ptr[i] != '%')
//     {
//         write(1, &ptr[i], 1);
//         i++;
//     }
// }

void ft_parsing(const char **s, int i, va_list name)
{
    // const char *p;
    // p = (char *)s;
    t_flag flag;
    const char *ptr;
    ft_list_flag(&flag);
    while ((*s)[i] != '%')
    {
        write(1,&(*s)[i],1);
            i++;            
    }
    i += 1;
    while ((*s)[i] && (*s)[i] != '.')
    {
        if ((*s)[i] == '0' || flag.zero != 1)
            flag.zero += 1;
        if ((*s)[i] == '-')
            flag.minus = 1; 
        if((*s)[i] >= '0' && (*s)[i] <= '9')
        {
            ptr = s[i];
            flag.digit = ft_atoi(ptr);
        }
        i++;
    }
    i += 1;
    while ((*s)[i] >= '0' && (*s)[i] <= '9')
    {
        flag.dot = (*s)[i];
        i++;
    }
    // if (*s[i] == 'c')
    //     ft_process_c(s[i]);
    // if (*s[i] == 's')
    //     ft_process_s(&s, i, &flag, name);
}
int ft_printf(const char *s, ...)
{
    va_list ap;
    int i;
    char *name;

    i = 0;
    va_start(ap,s);
    name = va_arg(ap, char *);

    ft_parsing(&s, i, name);
    va_end(ap);
    return (0);
}


int main()
{
    char *item;

    item = "abcdef";
    int i;
    item = "origin printf";
    ft_printf("origin printf= %s", item);
    printf("\n\n");
    printf("origin printf = %s",item);
}

