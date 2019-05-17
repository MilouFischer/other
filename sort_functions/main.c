/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:30:02 by efischer          #+#    #+#             */
/*   Updated: 2019/05/17 19:45:19 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_merge_sort(t_list **lst);

static void		ft_printlist(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putendl(lst->content);
		lst = lst->next;
	}
}

t_list			*ft_sort(t_list	*elem1, t_list *elem2)
{
	int		diff;
	t_list	*tmp;

	ft_printf("\nSort input:\n");
	ft_printlist(elem1);
	diff = ft_strcmp(elem1->content, elem2->content);
	if (diff > 0)
	{
		tmp = elem1;
		elem1 = elem2;
		elem2 = tmp;
		elem2->next = elem1->next;
		elem1->next = elem2;
	}
	ft_printf("\nSort output:\n");
	ft_printlist(elem1);
	return (elem1);
}

int				main(void)
{
	char	*tab[] = {"tete", "titi", "toto", "tutu", "tyty", "tztz"};
	t_list	*lst;
	size_t	i;

	i = 0;
	lst = NULL;
	while (tab[i] != NULL)
	{
		ft_lstadd(&lst, ft_lstnew(tab[i], sizeof(tab[i])));
		i++;
	}
	ft_printlist(lst);
	ft_merge_sort(&lst);
	ft_putchar('\n');
	ft_printlist(lst);
	return (0);
}
