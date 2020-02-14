/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:18:01 by efischer          #+#    #+#             */
/*   Updated: 2020/02/14 15:37:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <limits.h>
# include <termios.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# include "libft.h"
# include "vctlib.h"
//# include "ft_getopt.h"
//# include "error.h"
//# include "ft_errno.h"
# include "arithmetic_exp.h"

# ifndef PATH_MAX
# define PATH_MAX 1024
# endif

/* Flags of instruction type of redirection */
# define IOTYPE  0xF		/* type: bits 0:3 */
# define IOREAD  0x1		/* < */
# define IOWRITE 0x2		/* > */
# define IORDWR  0x3		/* <>: todo */
# define IOHERE  0x4		/* << (here file) */
# define IOCAT   0x5		/* >> */
# define IODUP   0x6		/* <&/>& */

/* Flags for complex redirection */
# define FILENAME  0x1
# define DEST      0x2
# define HEREWORD  0x4
# define FDCLOSE   0x8
# define NOFORK    0x10

char	*short_logical_path(char **cwd);
char	*short_physical_path(char **cwd);

extern char	g_pwd[PATH_MAX];

/* Union containing Descriptor or filename */
typedef union {
	int	dest;         /* Place to redirect to or .... */
	char	*filename;    /* filename to redirect to or ... */
	char	*hereword;    /* here-doc content used as input. */
}	t_redirectee;

/* A redirection structure for process redirections */
/* Structure describing a redirection */
struct	s_redirection
{
	struct s_redirection	*next;         /* next redirection or NULL */
	t_redirectee		redirector;    /* descriptor or varname to be redirected cf man dup2() */
	int			instruction;   /* what to do with the information, i.e. redirection type */
	int			flags;         /* additional information for complex redirections */
	t_redirectee		redirectee;    /* file descriptor or filename */
	char			*here_doc_eof; /* the word that appeared in <<eof */
	int			save;          /* saved fd for redir undo */
};

/* A process is a single process.  */
struct s_process
{
  struct s_process	*next;       /* next process in pipeline */
  char			**argv;      /* for exec */
  pid_t			pid;         /* process ID, given at fork time in job.c,
						uses waitpid (waitpid is not called when & at end of job) */
  char			completed;   /* true if process has completed */
  char			stopped;     /* true if process has stopped */
  int			status;      /* reported status value */
  struct s_redirection	*redir;      /* all recirections to be applied */
};

/* A job is a pipeline of processes.  */
struct s_job
{
  struct s_job		*next;          /* next active job */
  char			*command;       /* command line, used for messages */
  struct s_process	*first_process; /* list of processes in this job */
  pid_t			pgid;           /* process group ID */
  char			notified;       /* true if user told about stopped job */
  struct termios	tmodes;         /* saved terminal modes */
  int			stdin;          /* standard i/o channels */
  int			stdout;         /* standard i/o channels */
  int			stderr;         /* standard i/o channels */
};

typedef struct s_process	t_process;
typedef struct s_job		t_job;
typedef struct s_redirection	t_redirection;

/* The active jobs are linked into a list. This is its head. */
extern t_job		*first_job;
extern pid_t		shell_pgid;
extern struct termios	shell_tmodes;
extern int		shell_terminal;
extern int		shell_is_interactive;

int	init_shell(void);
void	launch_job(t_job *j, int foreground);
void	format_job_info (t_job *j, const char *status);
void	wait_for_job(t_job *j);
void    continue_job(t_job *j, int foreground);
void    free_job(t_job *j);
int	launch_process(t_process *p, pid_t pgid, int infile, int outfile, int errfile, int foreground);
void	free_process(t_process *p);
int     execute_process(char **argv, char **envp);

int     launch_builtin(t_process *p);
int	has_redirections(int type);
t_redirection	*build_redirections(t_list **lst);
int	get_tokentype(t_list *lst);
char	*get_tokvalue(t_list *lst);
int	do_redirection(t_redirection *r);
int	undo_redirection(t_redirection *r);

# define TRUE		1
# define FALSE		0

# define BUF_SIZE	32
# define NB_TOKEN	25
# define NB_BRACKET	3
# define TAB_END	-1

typedef struct		s_token
{
	uint64_t		type;
	char			*value;
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
	ANDGREAT,
	ANDLESS,
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

/*typedef struct	s_ast
{
	uint64_t	type;
	t_list		*content;
	void		*left;
	void		*right;
}				t_ast;*/

int		lexer(char* str, t_ast **ast);
int		parser(t_ast *ast);
int		bracket(t_list *lst, uint64_t *buffer, size_t index);
void	debug(t_list *lst);
int		get_stdin(char **line);
int		initialize_prompt_fd(void);
int		execute_job(t_list *lst, int foreground);
_Bool   prompt_display(int status);
int		path_concat(char **bin);
int		get_next_token(const char *str, t_token *token);
int    	set_minimal_env(void);
void    del(void *content, size_t content_size);
int     ft_atoifd(const char *str);
void	debug_ast(t_ast *ast);
void	ast_order(t_ast **ast);
void	astdel(t_ast **ast);
int		parser_pipeline(t_list *lst, uint64_t *buffer, size_t index, uint64_t *type);
int		execute_node(t_ast *node, int foreground);
int		build_ast(uint64_t type, t_ast **ast, t_list *lst);
int		ft_is_space_tab(int c);
char	*ft_join_free(char *s1, char *s2, int op);
int		ft_ismeta(int c);
int		expansions(t_ast *ast);

extern int	g_retval;

struct	s_tags
{
	char	*opentag;
	int	(*f)(size_t*, char**, const char*, const char*);
	char	*closetag;
};

struct	s_param
{
	char	*pname;
	char	*(*g)(const char*);
};

int		treat_expansions(t_list *lst);
int		getenv_content(char **content, char *str, const char *closetag);
size_t		ft_varlen(const char *s, const char *closetag);
int		is_a_valid_chr(const char c);
int		is_valid_param(const char *str);
int		parameter_expansions(size_t *index, char **str,
		const char *opentag, const char *closetag);
int		tilde_expansion(size_t *index, char **str,
		const char *opentag, const char *closetag);

#endif
