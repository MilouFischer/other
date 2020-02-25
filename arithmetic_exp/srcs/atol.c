#include "libft.h"
#include "shell.h"

long long	ft_atol(const char *str)
{
	size_t				i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		nbr = str[i++] - '0' + nbr * 10;
	if (str[0] == '-')
		nbr = -nbr;
	return (nbr);
}
