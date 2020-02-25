/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:58:48 by efischer          #+#    #+#             */
/*   Updated: 2020/02/14 15:16:22 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shell.h"

static void	init_ar_token_tab(int **ar_token_tab)
{
	int		token_start[NB_AR_TOKEN] = { NB, TAB_END };
	int		token_nb[NB_AR_TOKEN] = { PLUS, MIN, MULT, DIV, MOD,
							AR_END, TAB_END };
	int		token_op[NB_AR_TOKEN] = { NB, TAB_END };

	ar_token_tab[AR_START] = token_start;
	ar_token_tab[AR_END] = NULL;
	ar_token_tab[NB] = token_nb;
	ar_token_tab[PLUS] = token_op;
	ar_token_tab[MIN] = token_op;
	ar_token_tab[MULT] = token_op;
	ar_token_tab[DIV] = token_op;
	ar_token_tab[MOD] = token_op;
	ar_token_tab[OP_PAR] = NULL;
	ar_token_tab[CL_PAR] = NULL;
}

static int	check_next_ar_token(uint64_t type, int *token_tab)
{
	size_t	token_index;
	int		ret;

	ret = FAILURE;
	token_index = 0;
	if (token_tab != NULL)
	{
		while (token_tab[token_index] != TAB_END)
		{
			if (type == (uint64_t)token_tab[token_index])
			{
				ret = SUCCESS;
				break ;
			}
			token_index++;
		}
	}
	return (ret);
}

int			arithmetic_parser(t_list *lst)
{
	static int	*token_tab[NB_AR_TOKEN];
	ssize_t		ret;
	uint64_t	token_type;
	int			token_index;

	ret = SUCCESS;
	init_ar_token_tab(token_tab);
	while (lst->next != NULL)
	{
		token_index = ((t_token*)(lst->content))->type;
		lst = lst->next;
		token_type = ((t_token*)(lst->content))->type;
		ret = check_next_ar_token(token_type, token_tab[token_index]);
		if (ret == FAILURE)
			break ;
	}
	return (ret);
}
