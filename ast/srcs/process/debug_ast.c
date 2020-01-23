#include "libft.h"
#include "ast.h"

void	debug_ast(t_ast *ast)
{
	if (ast == NULL)
		return ;
	if (ast->left != NULL)
	{
		debug_ast(ast->left);
		ft_putendl("LEFT");
		debug(ast->content);
	}
	else
	{
		if (ast->type == SEMI)
			ft_putendl("SEMI");
		if (ast->type == AND)
			ft_putendl("AND");
		if (ast->type == AND_IF)
			ft_putendl("AND_IF");
		if (ast->type == OR_IF)
			ft_putendl("OR_IF");
		debug(ast->content);
	}
	if (ast->right != NULL)
	{
		ft_putendl("RIGHT");
		debug_ast(ast->right);
	}
}
