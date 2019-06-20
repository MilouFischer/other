#include "process_str.h"

static int	read_rest(char **line, char **rest)
{
	char	*tmp_rest;
	char	*tmp;

	tmp_rest = ft_strchr(*rest, '\n');
	if (tmp_rest == NULL)
	{
		*line = ft_strdup(*rest);
		ft_strdel(rest);
		return (0);
	}
	else
	{
		tmp = ft_strsub(*rest, 0, tmp_rest - *rest);
		*line = ft_join_free(*line, tmp, 3);
		tmp_rest = ft_strdup(tmp_rest);
		ft_strdel(rest);
		if (*(tmp_rest + 1) != '\0')
			*rest = ft_strdup(tmp_rest + 1);
		ft_strdel(&tmp_rest);
		return (1);
	}
}

static int	read_line(const int fd, char **line, char **rest)
{
	char	buf[BUF_SIZE + 1];
	char	*tmp;
	ssize_t	ret;

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*rest = ft_strchr(buf, '\n');
		if (*rest == NULL)
			*line = ft_join_free(*line, buf, 1);
		else
		{
			tmp = ft_strsub(buf, 0, *rest - buf);
			*line = ft_join_free(*line, tmp, 3);
			*rest = ft_strdup((*rest) + 1);
			return (1);
		}
	}
	return (ret);
}

int			get_next_line_test(const int fd, char **line)
{
	static char	*rest;
	ssize_t		ret;

	ret = 0;
	*line = NULL;
	if (fd < 0 || line == NULL)
		return (EXIT_FAILURE);
	if (rest != NULL)
	{
		if (read_rest(line, &rest) == TRUE)
			return (1);
	}
	ret = read_line(fd, line, &rest);
	if (*line != NULL)
		return (1);
	return (ret);
}
