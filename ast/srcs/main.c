#include "libft.h"
#include "ast.h"

void	del(void *content, size_t content_size)
{
	(void)content_size;
	vct_del(((t_token*)(content))->value);
	free(content);
}

int 	main(int ac, char **av)
{
//	int			index;
//	t_list		*lst;
	t_ast		*ast;
//	uint64_t	buffer[BUF_SIZE];

//	lst = NULL;
	ast = NULL;
//	index = 0;
	if (ac == 2)
	{
		lexer(av[1], &ast);
//		ast_order(&ast);
	}
//	ft_putendl("DEBUG LST\n");
//	debug(lst);
	ft_putendl("\nDEBUG AST\n");
	debug_ast(ast);
//	ft_lstdel(&lst, del);
	return (EXIT_SUCCESS);
}
