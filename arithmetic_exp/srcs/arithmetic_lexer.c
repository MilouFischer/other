/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:58:33 by efischer          #+#    #+#             */
/*   Updated: 2020/02/14 15:48:11 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"
#include "arithmetic_exp.h"

int		arithmetic_lexer(const char *str, t_ast **ast)
{
	int			ret;
	uint64_t	type;
	size_t		pos;
	t_list		*lst;

	pos = 0;
	while (str[pos] != '\0')
	{
		type = NONE;
		lst = NULL;
		ret = border_token_list(&lst, START);
		if (ret == SUCCESS)
			ret = get_
	}
	return (ret);
}
