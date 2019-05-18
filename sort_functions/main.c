/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:30:02 by efischer          #+#    #+#             */
/*   Updated: 2019/05/18 15:52:42 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_merge_sort(t_list **lst);

void		ft_printlist(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
}

int				main(void)
{
	char	*tab[] = {"tete", "tyty", "toto", "tutu", "titi", "tztz", "tata", NULL};
	t_list	*lst;
	size_t	i;

	i = 0;
	lst = NULL;
	while (tab[i] != NULL)
	{
		ft_lstadd(&lst, ft_lstnew(tab[i], ft_strlen(tab[i]) + 1));
		i++;
	}
	ft_printlist(lst);
	ft_merge_sort(&lst);
	ft_putchar('\n');
	ft_printlist(lst);
	return (0);
}
