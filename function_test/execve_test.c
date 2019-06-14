#include "libft.h"

int		main(int ac, char **av)
{
	(void)ac;
	ft_print_tab(av);
	execve("/bin/ls", av, NULL);
	return (0);
}
