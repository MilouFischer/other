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
	size_t			nb_arg_on_line;
	size_t			nb_line;
	size_t			i;

	(void)av;
	ioctl(0, TIOCGWINSZ, &w);
	nb_line = w.ws_row / padding;
	nb_arg_on_line = ac / nb_line;
	while (nb_line > 0)
	{
		i = 0;
		while (i < nb_arg_on_line)
		{
			ft_printf("%-*s", padding, *av++);
			i++;
		}
		ft_putchar('\n');
		nb_line--;
	}
	//ft_printf("nb_line: %d, nb_arg_on_line: %d\n", nb_line, nb_arg_on_line);
}

int				main(int ac, char **av)
{
	size_t	padding;

	ft_get_padding(av, &padding);
	ft_print_column(ac, av, padding);
	ft_putchar('\n');
	return (0);
}
