<<<<<<< HEAD
#include "libft.h"
#include "shell.h"

static int	get_next_ar_token(const char *str, t_ar_ast **ast)
{
	static char	*ar_token_tab[NB_TOKEN];
	size_t		token_index;
	size_t		pos;

	pos = 0;
	token_index = 0;
	init_ar_token_tab(ar_token_tab);
	while (token < NB_TOKEN)
	{
		if (ft_strnequ(str, ar_token_tab[token_index]))
		{
			token->type = token_index;
			pos = ft_strlen(token_tab[token_index]);
		}
		token_index++;
	}
	if (token_index == NB_TOKEN)
		pos = get_nb_token(str, token);
	return (pos);
}

int			arithmetic_lexer(const char *str, t_ar_ast **ast)
{
	size_t	ret;
	size_t	pos;
	t_token	token;

	pos = 0;
	ret = SUCCESS;

	ret = build_ar_ast(ast, START);
	while (str[pos] != '\0')
	{
		ft_bzero(token, sizeof(token));
		pos += get_next_ar_token(str, &token);
		ret = build_ar_ast(ast, token);
	}
	ret = build_ar_ast(ast, END);
=======
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
>>>>>>> 422646de6db416f169e3c69d1bdc6eee46e12aad
	return (ret);
}
