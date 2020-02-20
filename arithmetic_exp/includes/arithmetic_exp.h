<<<<<<< HEAD
#ifndef ARITHMETIC_EXP_H
# define ARITHMETIC_EXP_H

typedef struct	arithmetic_ast
{
	t_arithmetic_ast	*left;
	t_arithmetic_ast	*right;
	char				*value;

}				t_arithmetic_ast;
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_exp.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:09:10 by efischer          #+#    #+#             */
/*   Updated: 2020/02/14 15:37:04 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARITHMETIC_EXP_H
# define ARITHMETIC_EXP_H

# include "libft.h"
# include "shell.h"

typedef struct	s_ast
{
	uint64_t	type;
	t_list		*content;
	void		*left;
	void		*right;
}				t_ast;

int		arithmetic_lexer(const char *str, t_ast **ast);
int		arithmetic_parser(t_ast **ast);
>>>>>>> 422646de6db416f169e3c69d1bdc6eee46e12aad

#endif
