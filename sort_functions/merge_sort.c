/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:56:52 by efischer          #+#    #+#             */
/*   Updated: 2019/05/17 19:53:52 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



void		ft_merge_sort(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;
	char	*s1;
	char	*s2;

	head = *lst;
	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	while ((*lst)->next != NULL)
	{
		s1 = (char *)((*lst)->content);
		s2 = (char *)((*lst)->next->content);
		if (ft_strcmp(s1, s2) > 0)
		{
			tmp->next = (*lst)->next;
			(*lst)->next = (*lst)->next->next;
			tmp->next->next = *lst;
			*lst = head;
		}
		tmp = *lst;
		*lst = (*lst)->next;
	}
	*lst = head;
}
