#include "libft.h"
#include "shell.h"

int		ft_is_space_tab(int c)
{
	int		ret;

	ret = FALSE;
	if (c == ' ' || c == '\t')
		ret = TRUE;
	return (ret);
}

static int	add_token_to_list(t_token *token, t_list **lst)
{
	t_list	*new;
	ssize_t	ret;

	ret = SUCCESS;
	new = ft_lstnew(token, sizeof(*token));
	if (new == NULL)
		ret = FAILURE;
	ft_lstaddend(lst, new);
	return (ret);
}

static int	border_token_list(t_list **lst, uint64_t token_type)
{
	t_token	token;
	ssize_t	ret;

	ft_bzero(&token, sizeof(token));
	token.type = token_type;
	ret = add_token_to_list(&token, lst);
	return (ret);
}

static void	init_ar_token_tab(char **ar_token_tab)
{
	ar_token_tab[AR_START] = NULL;
	ar_token_tab[AR_END] = NULL;
	ar_token_tab[NB] = NULL;
	ar_token_tab[PLUS] = "+";
	ar_token_tab[MIN] = "-";
	ar_token_tab[MULT] = "*";
	ar_token_tab[DIV] = "/";
	ar_token_tab[MOD] = "%";
	ar_token_tab[OP_PAR] = "(";
	ar_token_tab[CL_PAR] = ")";
}

static int	get_nb_token(const char *str, t_token *token)
{
	size_t	pos;

	pos = 0;
	while (ft_isdigit(str[pos]) == TRUE)
		pos++;
	token->type = NB;
	token->value = ft_strndup(str, pos);
	return (pos);
}

static int	get_next_ar_token(const char *str, t_token *token)
{
	static char	*ar_token_tab[NB_AR_TOKEN];
	size_t		token_index;
	size_t		pos;

	pos = 0;
	token_index = 0;
	init_ar_token_tab(ar_token_tab);
	while (token_index < NB_AR_TOKEN)
	{
		pos = ft_strlen(ar_token_tab[token_index]);
		if (ft_strnequ(str, ar_token_tab[token_index], pos) == TRUE)
		{
			token->type = token_index;
			break ;
		}
		token_index++;
		pos = 0;
	}
	if (token_index == NB_AR_TOKEN)
		pos = get_nb_token(str, token);
	return (pos);
}

int			arithmetic_lexer(const char *str, t_list **lst)
{
	ssize_t	ret;
	size_t	pos;
	t_token	token;

	pos = 0;
	ret = SUCCESS;
	while (ft_is_space_tab(str[pos]) == TRUE)
		pos++;
	if (str[pos] != '\0')
	{
		ret = border_token_list(lst, AR_START);
		while (str[pos] != '\0')
		{
			while (ft_is_space_tab(str[pos]) == TRUE)
				pos++;
			ft_bzero(&token, sizeof(token));
			pos += get_next_ar_token(str + pos, &token);
			add_token_to_list(&token, lst);
		}
		ret = border_token_list(lst, AR_END);
	}
	return (ret);
}
