#include "libft.h"
#include "shell.h"

void	del(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_token*)(content))->value);
	free(content);
}

int		main(int ac, char **av)
{
	t_list		*lst;
	ssize_t		ret;
	long long	res;

	res = 0;
	ret = SUCCESS;
	lst = NULL;
	if (ac == 2)
	{
		ret = arithmetic_lexer(av[1], &lst);
		if (ret == SUCCESS && lst != NULL)
		{
			ret = arithmetic_parser(lst);
			if (ret == FAILURE)
				ft_putendl_fd("Parse error", 2);
			else
			{
				res = exec_ar_exp(lst);
				ft_printf("res: %lld\n", res);
			}
		}
//		ar_debug(lst);
		ft_lstdel(&lst, del);
	}
	return (ret);
}
