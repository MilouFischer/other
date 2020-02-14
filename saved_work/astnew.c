/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:02:54 by efischer          #+#    #+#             */
/*   Updated: 2020/02/12 11:03:18 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"

t_ast		*astnew(t_list *lst, uint64_t type)
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
