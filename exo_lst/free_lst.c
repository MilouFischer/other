/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 10:44:36 by efischer          #+#    #+#             */
/*   Updated: 2019/05/29 11:34:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

void	free_lst_content(void *content, size_t content_size)
{
	if (content_size != 0)
	{
		ft_strdel(&((t_test*)(content))->param1);
		ft_strdel(&((t_test*)(content))->param2);
		ft_strdel(&((t_test*)(content))->param3);
	}
	free(content);
}

int		main(void)
{
	t_list	*lst;
	t_list	*tmp;
	t_test	test;

	lst = NULL;
	ft_bzero(&test, sizeof(test));
	test.param1 = ft_strdup("bonjour");
	test.param2 = ft_strdup("ca roule");
	test.param3 = ft_strdup("test");
	ft_lstadd(&lst, ft_lstnew(&test, sizeof(test)));
	ft_bzero(&test, sizeof(test));
	test.param1 = ft_strdup("wesh");
	test.param2 = ft_strdup("lkhf");
	test.param3 = ft_strdup("salut");
	ft_lstadd(&lst, ft_lstnew(&test, sizeof(test)));
	tmp = lst;
	while (lst != NULL)
	{
		ft_putendl(((t_test*)(lst->content))->param1);
		ft_putendl(((t_test*)(lst->content))->param2);
		ft_putendl(((t_test*)(lst->content))->param3);
		lst = lst->next;
	}
	ft_lstdel(&tmp, free_lst_content);
	while (1);
	return (0);
}
