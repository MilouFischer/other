#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	ssize_t	ret;

	fd = 0;
	line = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY, O_WRONLY, O_RDWR);
		if (fd == FAILURE)
			return (EXIT_FAILURE);
	}
	while ((ret = get_next_line_test(fd, &line)) > 0)
	{
		if (ret != FAILURE && line != NULL)
			ft_putstr(line);
		ft_strdel(&line);
		line = NULL;
		ft_putnbr(ret);
	}
	close(fd);
	ft_putnbr(ret);
	return (ret);
}
