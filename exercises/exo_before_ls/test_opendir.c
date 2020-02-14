/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_opendir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:06:09 by efischer          #+#    #+#             */
/*   Updated: 2019/05/13 13:36:58 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "../libft/includes/libft.h"

int		main(int ac, char **av)
{
	void			*dir;
	char			*name;
	struct dirent	*dirent;

	name = ".";
	if (ac >= 2)
		name = av[1];
	dir = opendir(name);
	if (dir == NULL)
	{
		if (errno != ENOTDIR)
			perror(ft_asprintf("ft_ls: file not found '%s'", name));
		else
			ft_putendl(name);
		return (-1);
	}
	while ((dirent = readdir(dir)) != NULL)
	{
		if (dirent->d_name[0] != '.')
			ft_putendl(dirent->d_name);
	}
	(void)closedir(dir);
	return (0);
}
