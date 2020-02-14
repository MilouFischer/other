/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getdirinfo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:11:30 by efischer          #+#    #+#             */
/*   Updated: 2019/05/14 14:15:49 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include "../libft/includes/libft.h"
#include "test.h"

static const char	*ft_get_time(const char *brut_tm)
{
	char	**tab;
	char	final_tm[13];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tab = ft_strsplit(brut_tm, ' ');
	while (tab[1][j] != '\0')
		final_tm[i++] = tab[1][j++];
	final_tm[i++] = ' ';
	j = 0;
	while (tab[2][j] != '\0')
		final_tm[i++] = tab[2][j++];
	final_tm[i++] = ' ';
	j = 0;
	while (i < 12)
		final_tm[i++] = tab[3][j++];
	final_tm[i] = '\0';
	return (ft_strdup(final_tm));
}

static void		ft_init_mode_tab(const char *mode_tab[8])
{
	mode_tab[0] = "---";
	mode_tab[1] = "--x";
	mode_tab[2] = "-w-";
	mode_tab[3] = "-wx";
	mode_tab[4] = "r--";
	mode_tab[5] = "r-x";
	mode_tab[6] = "rw-";
	mode_tab[7] = "rwx";
}

static const char	*ft_get_type(int nb_mode)
{
	int			octal_mode;

	octal_mode = ft_atoi(ft_itoa_base(nb_mode, 8)) / 1000;
	if (octal_mode == 40)
		return (ft_strdup("Repertoire"));
	if (octal_mode == 100)
		return (ft_strdup("Fichier"));
	if (octal_mode == 120)
		return (ft_strdup("Lien symbolique"));
	else
		return (ft_strdup("Inconnu"));
}

static const char	*ft_get_mode(int nb_mode)
{
	char		*final_mode;
	int			octal_mode;
	const char	*mode_tab[8];
	size_t		index;
	size_t		i;

	i = 0;
	ft_init_mode_tab(mode_tab);
	octal_mode = ft_atoi(ft_itoa_base(nb_mode, 8));
	index = octal_mode / 100 % 10;
	final_mode = ft_strdup(mode_tab[index]);
	index = octal_mode / 10 % 10;
	final_mode = ft_join_free(final_mode, (char*)mode_tab[index], 1);
	index = octal_mode % 10;
	final_mode = ft_join_free(final_mode, (char*)mode_tab[index], 1);
	return (final_mode);
}

static void		ft_print_dir_info(t_dir *dir)
{
	ft_printf("Nom: %s\n", dir->name);
	ft_printf("Type: %s\n", dir->type);
	ft_printf("Modes: %s\n", dir->mode);
	ft_printf("Nombre de liens: %ld\n", dir->link);
	ft_printf("Proprietaire: %s\n", dir->uid);
	ft_printf("Groupe: %s\n", dir->gid);
	ft_printf("Taille: %lld octets\n", dir->size);
	ft_printf("Date de derniere modification: %s", dir->time);
}

int				main(int ac, char **av)
{
	struct stat		buf;
	struct passwd	usr;
	struct group	grp;
	t_dir			*dir;

	if (ac != 2)
	{
		ft_putendl("usage: ./exe <path>");
		return (0);
	}
	if ((dir = (t_dir*)malloc(sizeof(t_dir))) == NULL)
		return (-1);
	if ((stat(av[1], &buf)) != -1)
	{
		usr = *getpwuid(buf.st_uid);
		grp = *getgrgid(buf.st_gid);
		dir->name = av[1];
		dir->type = ft_get_type(buf.st_mode);
		dir->mode = ft_get_mode(buf.st_mode);
		dir->link = buf.st_nlink;
		dir->uid = usr.pw_name;
		dir->gid = grp.gr_name;;
		dir->size = buf.st_size;
		dir->time = ft_get_time(ctime(&buf.st_ctime));
		ft_print_dir_info(dir);
	}
	return (0);
}
