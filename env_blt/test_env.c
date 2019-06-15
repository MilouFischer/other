/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:36:05 by efischer          #+#    #+#             */
/*   Updated: 2019/06/15 15:19:21 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	get_env_lst(char **envp, t_list **lst)
{
	t_env	env;
	char	**tab;
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_bzero(&env, sizeof(env));
		env.all = ft_strdup(envp[i]);
		tab = ft_strsplit(envp[i], '=');
		env.name = ft_strdup(tab[0]);
		env.value = ft_strdup(tab[1]);
		ft_free_tab(tab);
		ft_lstaddend(lst, ft_lstnew(&env, sizeof(env)));
		i++;
	}
}

static void	find_env(t_list *lst, char *arg)
{
	while (lst != NULL)
	{
		if (ft_strequ(((t_env*)(lst->content))->name, arg) == TRUE)
		{
			ft_putendl(((t_env*)(lst->content))->all);
			return ;
		}
		lst = lst->next;
	}
}

int			main(int ac, char **av, char **envp)
{
	t_list	*lst;

	lst = NULL;
	ft_bzero(&lst, sizeof(lst));
	get_env_lst(envp, &lst);
	if (ac > 1)
	{
		while (*av != NULL)
			find_env(lst, *av++);
	}
	else
		while (lst != NULL)
		{
			ft_putendl(((t_env*)(lst->content))->all);
			lst = lst->next;
		}
	return (0);
}
