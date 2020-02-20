<<<<<<< HEAD
#include "libft.h"
#include "shell.h"

int		main(int ac, char **av)
{
	t_arithmetic_ast	*ast;
	size_t				ret;

	ret = SUCCESS;
	ast = NULL;
	if (ac == 2)
	{
		ret = arithmetic_lexer(av[1], &ast);
		if (ret == FAILURE)
			ft_putendl_fd("Parse error", 2);
	}
	return (ret);
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:50:39 by efischer          #+#    #+#             */
/*   Updated: 2020/02/14 15:40:33 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "arithmetic_exp.h"

void	del(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel(&((t_token*)(content))->value);
	free(content);
}

void	astdel(t_ast **ast)
{
	if (*ast != NULL)
	{
		ft_lstdel(&(*ast)->content, del);
		if ((*ast)->left != NULL)
			astdel((t_ast**)&(*ast)->left);
		if ((*ast)->right != NULL)
			astdel((t_ast**)&(*ast)->right);
		free(*ast);
		*ast = NULL;
	}
}

int		main(int ac, char **av)
{
	t_ast	*ast;

	ast = NULL;
	if (ac == 2)
	{
		arithmetic_lexer(av[1], &ast);
		debug_ast(ast);
		if (ast != NULL)
		{
			if (arithmetic_parser(&ast) == FAILURE)
				ft_putendl_fd("Parse error", 2);
		}
		astdel(&ast);
	}
	return (EXIT_SUCCESS);
>>>>>>> 422646de6db416f169e3c69d1bdc6eee46e12aad
}
