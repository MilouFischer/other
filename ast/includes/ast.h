#ifndef AST_H
# define AST_H

# include <termios.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>

# include "libft.h"
# include "vctlib.h"

# define BUF_SIZE	32
# define NB_TOKEN	23
# define NB_BRACKET	3
# define TAB_END	-1

typedef struct		s_token
{
	uint64_t		type;
	t_vector		*value;
}					t_token;

enum	e_bracket
{
	PARENTHESIS,
	WHILE_LOOP,
	EARDOCS
};

enum	e_token
{
	SEMI,
	OR_IF,
	PIPE,
	AND_IF,
	GREATAND,
	LESSAND,
	AND,
	DSEMI,
	OP_PARENTHESIS,
	CL_PARENTHESIS,
	WHILE_WORD,
	DONE,
	DGREAT,
	DLESS,
	GREAT,
	LESS,
	WORD,
	IO_NB,
	END_OF_FILE,
	COMMENT,
	START,
	END,
	NONE
};

typedef struct	s_bracket
{
	uint64_t	open;
	uint64_t	close;
}				t_bracket;

typedef struct	s_ast
{
	uint64_t	type;
	t_list		*content;
	void		*left;
	void		*right;
}				t_ast;

int		lexer(const char* str, t_ast **ast);
int		parser(t_ast *ast, uint64_t *buffer, size_t index);
int		bracket(t_list *lst, uint64_t *buffer, size_t index);
void	debug(t_list *lst);
int		get_stdin(char **line);
int		initialize_prompt_fd(void);
int		launch_all_jobs(t_list *lst);
_Bool   prompt_display(int status);
int		path_concat(char **bin);
int		get_next_token(const char *str, t_token *token);
int    		set_minimal_env(void);
void    del(void *content, size_t content_size);
int             ft_atoifd(const char *str);

int				make_ast(t_list *lst, t_ast **ast);
void			debug_ast(t_ast *ast);

extern int	g_retval;
extern char	g_pwd[];

#endif
