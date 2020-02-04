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
	t_ast		*ast;

	ast = NULL;
	if (ac == 2)
	{
		lexer(av[1], &ast);
		if (parser(ast) == FAILURE)
			ft_putendl("\nParse error\n");
		ast_order(&ast);
	}
	ft_putendl("\nDEBUG AST\n");
	debug_ast(ast);
	astdel(&ast);
	debug_ast(ast);
	return (EXIT_SUCCESS);
}
