#include "libft.h"
#include <sys/ioctl.h>

static void		ft_get_padding(char **av, size_t *padding)
{
	*padding = 0;
	while (*av != NULL)
	{
		if (ft_strlen(*av) + 1> *padding)
			*padding = ft_strlen(*av) + 1;
		av++;
	}
}

static void		ft_print_column(int ac, char **av, size_t padding)
{
	struct winsize	w;
	size_t			nb_max_by_line;
	size_t			nb_line;
	size_t			i;
	size_t			index;

	(void)ac;
	ioctl(0, TIOCGWINSZ, &w);
	nb_max_by_line = w.ws_col / padding;
	nb_line = ac / nb_max_by_line + 1;
	i = 0;
	while (i < nb_line)
	{
		index = i;
		while ((int)index < ac)
		{
			ft_printf("%-*s", padding, av[index]);
			index += nb_line;
		}
		ft_putchar('\n');
		i++;
	}
}

int				main(int ac, char **av)
{
	size_t	padding;

	ft_get_padding(av, &padding);
	ft_print_column(ac, av, padding);
	return (0);
}
