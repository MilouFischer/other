/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:45:03 by efischer          #+#    #+#             */
/*   Updated: 2019/06/18 12:07:33 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include "libft.h"

typedef struct	s_env
{
	char		*name;
	char		*value;
	char		*all;
}				t_env;

char	**ft_lst_to_char_tab(t_list *lst, char *(*f)(t_list *));

#endif
