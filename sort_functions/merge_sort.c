/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:56:52 by efischer          #+#    #+#             */
/*   Updated: 2019/05/17 17:24:06 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_merge_sort(t_list *lst, t_list *sort(t_list*, t_list*))
{
	while (lst != NULL)
	{
		if (lst->next != NULL)
			lst = sort(lst, lst->next);
		lst = lst->next;
	}
}
