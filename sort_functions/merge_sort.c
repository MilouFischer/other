/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:56:52 by efischer          #+#    #+#             */
/*   Updated: 2019/05/18 15:53:36 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printlist(t_list *lst);

/*void		ft_merge_sort(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	head = *lst;
	tmp = head;
	while (*lst != NULL && (*lst)->next != NULL)
	{
		if (ft_strcmp((*lst)->content, (*lst)->next->content) > 0)
		{
			if (*lst == head)
			{
				tmp = (*lst)->next;
				(*lst)->next = tmp->next;
				tmp->next = *lst;
				head = tmp;
			}
			else
			{
				tmp->next = (*lst)->next;
				(*lst)->next = (*lst)->next->next;
				tmp->next->next = *lst;
			}
			*lst = head;
		}
		else
		{
			tmp = *lst;
			*lst = (*lst)->next;
		}
	}
	*lst = head;
}*/

static void	ft_share_lst(t_list **lst)
{
	t_list	*find_last_link;

	find_last_link = *lst;
	while (find_last_link->next != NULL)
	{
		find_last_link = find_last_link->next;
		if (find_last_link->next != NULL)
		{
			*lst = (*lst)->next;
			find_last_link = find_last_link->next;
		}
	}
}

t_list		*ft_merge_list(t_list *lst1, t_list *lst2)
{
	t_list	*head;
	t_list	*tmp;

	if (ft_strcmp(lst1->content, lst2->content) > 0)
	{
		head = lst2;
		lst2 = lst2->next;
	}
	else
	{
		head = lst1;
		lst1 = lst1->next;
	}
	tmp = head;
	while (lst1 != NULL && lst2 != NULL)
	{
		if (ft_strcmp(lst1->content, lst2->content) > 0)
		{
			tmp->next = lst2;
			lst2 = lst2->next;
		}
		else
		{
			tmp->next = lst1;
			lst1 = lst1->next;
		}
		tmp = tmp->next;
	}
	while (lst1 != NULL)
	{
		tmp->next = lst1;
		lst1 = lst1->next;
		tmp = tmp->next;
	}
	while (lst2 != NULL)
	{
		tmp->next = lst2;
		lst2 = lst2->next;
		tmp = tmp->next;
	}
	return (head);
}

void		ft_merge_sort(t_list **lst)
{
	t_list	*lst1;
	t_list	*lst2;

	if (lst == NULL || (*lst)->next == NULL)
		return ;
	lst1 = *lst;
	ft_share_lst(lst);
	lst2 = (*lst)->next;
	(*lst)->next = NULL;
	ft_printf("\nlst1:\n");
	ft_printlist(lst1);
	ft_printf("\nlst2:\n");
	ft_printlist(lst2);
	ft_merge_sort(&lst1);
	ft_merge_sort(&lst2);
	*lst = ft_merge_list(lst1, lst2);
}
