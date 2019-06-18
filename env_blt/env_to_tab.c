/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 11:09:57 by efischer          #+#    #+#             */
/*   Updated: 2019/06/18 11:36:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	**env_to_tab(t_list *lst)
{
	char	**tab;
	size_t	len;
	size_t	i;

	i = 0;
	len	= ft_lstlen(lst);
	tab = (char**)malloc(sizeof(char*) * (len + 1));
	if (tab == NULL)
		return (NULL);
	while (lst != NULL)
	{
		tab[i] = ft_strdup(((t_env*)(lst->content))->all);
		lst = lst->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
