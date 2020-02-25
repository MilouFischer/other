#include "libft.h"
#include "shell.h"

static void	init_token_tab(char **token_tab)
{
	token_tab[AR_START] = "AR_START";
	token_tab[AR_END] = "AR_END";
	token_tab[NB] = "NB";
	token_tab[PLUS] = "PLUS";
	token_tab[MIN] = "MIN";
	token_tab[MULT] = "MULT";
	token_tab[DIV] = "DIV";
	token_tab[MOD] = "MOD";
	token_tab[OP_PAR] = "OP_PAR";
	token_tab[CL_PAR] = "CL_PAR";
}

static void	print(t_list *lst, t_list **elem)
{
	static char	*token_tab[NB_AR_TOKEN];
	char		*print_content;
	char		*tmp;
	size_t		i;

	i = 0;
	print_content = NULL;
	init_token_tab(token_tab);
	while (i < NB_AR_TOKEN)
	{
		tmp = NULL;
		if (((t_token*)(lst->content))->type == i)
		{
			if (i == NB)
				tmp = ((t_token*)(lst->content))->value;
			ft_asprintf(&print_content, "%s -> [%s]\n", token_tab[i], tmp);
			break ;
		}
		i++;
	}
	*elem = ft_lstnew(print_content, ft_strlen(print_content));
	ft_strdel(&print_content);
}

void		ar_debug(t_list *lst)
{
	ft_lstprint(lst, print);
}
