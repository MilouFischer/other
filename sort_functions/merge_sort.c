/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:56:52 by efischer          #+#    #+#             */
/*   Updated: 2019/05/18 14:09:44 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printlist(t_list *lst);

void		ft_merge_sort(t_list **lst)
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
		//	ft_printf("\nIn sort:\n");
		//	ft_printlist(head);
		}
		else
		{
			tmp = *lst;
			*lst = (*lst)->next;
		}
	}
	*lst = head;
}
