#include "libft.h"
#include "ast.h"

static t_ast	*astnew(t_list *lst, uint64_t type)
{
	t_ast	*ast;

	ast = (t_ast*)malloc(sizeof(t_ast));
	if (ast != NULL)
	{
		ft_bzero(ast, sizeof(t_ast));
		ast->type = type;
		ast->content = lst;
	}
	return (ast);
}

static void	node_rot(t_ast **ast, t_ast *prev_node)
{
	t_ast	*tmp;
	t_list	*content;

	if (prev_node == NULL)
		ft_putendl("prev_node == NULL");
	else
	{
		tmp = *ast;
		content = ((t_ast*)(*ast)->right)->content;
		prev_node->right = (*ast)->right;
		tmp->right = astnew(content, SEMI);
	}
}

void		ast_order(t_ast **ast)
{
	t_ast	*head;
	t_ast	*prev_node;

	head = *ast;
	prev_node = NULL;
	while ((*ast)->right)
	{
		if ((*ast)->type == AND_IF || (*ast)->type == OR_IF)
		{
			if (((t_ast*)((*ast)->right))->type == AND)
				node_rot(ast, prev_node);
		}
		prev_node = *ast;
		*ast = (*ast)->right;
	}
}
