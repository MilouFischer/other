/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 14:36:05 by efischer          #+#    #+#             */
/*   Updated: 2019/06/18 12:07:32 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void		get_env_lst(char **envp, t_list **lst)
{
	t_env	env;
	char	**tab;
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
	{
		ft_bzero(&env, sizeof(env));
		env.all = envp[i];
		tab = ft_strsplit(envp[i], '=');
		env.name = ft_strdup(tab[0]);
		env.value = ft_strdup(tab[1]);
		ft_free_tab(tab);
		ft_lstaddend(lst, ft_lstnew(&env, sizeof(env)));
		i++;
	}
}

static char		*get_string(t_list *lst)
{
	return (((t_env*)(lst->content))->all);
}

int				main(int ac, char **av, char **envp)
{
	t_list	*lst;
	char	**tab;

	(void)av;
	(void)ac;
	lst = NULL;
	ft_bzero(&lst, sizeof(lst));
	get_env_lst(envp, &lst);
	tab = ft_lst_to_char_tab(lst, get_string);
	if (tab == NULL)
		ft_putendl("Error");
	ft_print_tab(tab);
	return (0);
}
