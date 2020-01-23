#include "libft.h"
#include "ast.h"

static void		astadd_left(t_ast **ast, t_ast *new_ast)
{
	while ((*ast)->left != NULL)
		*ast = (*ast)->left;
	(*ast)->left = new_ast;
}

static void		astadd_right(t_ast **ast, t_ast *new_ast)
{
	if (*ast == NULL)
		*ast = new_ast;
	else
	{
		while ((*ast)->right != NULL)
			*ast = (*ast)->right;
		(*ast)->right = new_ast;
	}
}

static t_ast	*astnew(t_list *lst, uint64_t type)
{
	t_ast	*ast;

	ast = NULL;
	ast = (t_ast*)malloc(sizeof(t_ast));
	if (ast != NULL)
	{
		ft_bzero(ast, sizeof(t_ast));
		ast->type = type;
		ast->content = lst;
	}
	return (ast);
}

int				make_ast(t_list *lst, t_ast **ast)
{
	t_list	*head;
	t_list	*tmp;
	t_ast	*new_ast;

	head = lst;
	while (lst != NULL)
	{
		if (((t_token*)(lst->content))->type == AND
			|| ((t_token*)(lst->content))->type == AND_IF
			|| ((t_token*)(lst->content))->type == OR_IF
			|| ((t_token*)(lst->content))->type == SEMI
			|| ((t_token*)(lst->content))->type == END)
		{
			tmp = lst->next;
			new_ast = astnew(NULL, ((t_token*)(lst->content))->type);
			ft_lstdelone(&lst, del);
			astadd_left(&new_ast, astnew(head, SEMI));
			if (new_ast != NULL)
				astadd_right(ast, new_ast);
			else
				return (FAILURE);
			head = tmp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (SUCCESS);
}
