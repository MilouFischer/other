#include "libft.h"

int		main(int ac, char **av)
{
	t_vector	*vct;

	if (ac == 4)
	{
		vct = vct_newstr(av[1]);
		ft_putendl(vct->str);
		vct_insertstr(av[2], ft_atoi(av[3]), vct);
		write(1, vct->str, vct->len);
		vct_del(vct);
	}
	return (EXIT_SUCCESS);
}
