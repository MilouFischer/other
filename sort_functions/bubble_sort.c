# include "libft.h"

void	ft_bubble_sort(char	**tab)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (tab[i] != NULL)
	{
		j = i;
		while (tab[j] != NULL)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	**ft_get_args_tab(int ac, char **av)
{
	int		i;
	char	**tab;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * (ac + 1))) == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i] = av[i];
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int		main(int ac, char **av)
{
	char	**tab;

	if (ac == 1)
		return (-1);
	tab = ft_get_args_tab(ac - 1, av + 1);
	ft_bubble_sort(tab);
	ft_print_tab(tab);
	free(tab);
	return (0);
}
