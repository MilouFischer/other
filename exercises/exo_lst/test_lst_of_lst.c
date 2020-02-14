/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_of_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 18:50:26 by efischer          #+#    #+#             */
/*   Updated: 2019/05/15 19:03:22 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	t_list	*lst;
	t_list	*tmp;
	size_t	i;
	char	tab[3][5] = { "tata", "titi", "toto" };

	i = 0;
	lst = ft_lstnew(NULL, 0);
	tmp = lst;
	while (i < 3)
	{
		ft_lstadd(&lst, ft_lstnew(tab[i], ft_strlen(tab[i])));
		i++;
		lst = lst->next;
	}
	while (tmp != NULL)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
	}
	return (0);
}
