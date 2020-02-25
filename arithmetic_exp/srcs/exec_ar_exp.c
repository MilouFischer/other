#include "libft.h"
#include "shell.h"

static void	do_op(long long *nb_stack, uint64_t *op_stack,
				ssize_t *nb_index, ssize_t *op_index)
{
	while (op_stack[0] != 0)
	{
		if (op_stack[*op_index] == PLUS)
			do_add(nb_stack, nb_index);
		if (op_stack[*op_index] == MIN)
			do_sub(nb_stack, nb_index);
		if (op_stack[*op_index] == MULT)
			do_mult(nb_stack, nb_index);
		if (op_stack[*op_index] == DIV)
			do_div(nb_stack, nb_index);
		if (op_stack[*op_index] == MOD)
			do_mod(nb_stack, nb_index);
		op_stack[*op_index] = 0;
		(*op_index)--;
	}
}

static int	is_priority(uint64_t stack_op, uint64_t op)
{
	int		ret;

	ret = FALSE;
	if (stack_op == MULT || stack_op == DIV || stack_op == MOD)
		if (op == PLUS || op == MIN)
			ret = TRUE;
	return (ret);
}

long long	exec_ar_exp(t_list *lst)
{
	long long	res;
	long long	nb_stack[BUF_SIZE];
	uint64_t	op_stack[BUF_SIZE];
	ssize_t		nb_index;
	ssize_t		op_index;

	res = 0;
	nb_index = -1;
	op_index = -1;
	ft_bzero(nb_stack, BUF_SIZE);
	ft_bzero(op_stack, BUF_SIZE);
	if (((t_token*)(lst->content))->type == AR_START)
		lst = lst->next;
	else
	{
		ft_putendl_fd("List doesn't start with AR_START token, as it should be", 2);
		return (res);
	}
	while (((t_token*)(lst->content))->type != AR_END)
	{
		if (((t_token*)(lst->content))->type == NB)
		{
			nb_index++;
			nb_stack[nb_index] = ft_atol(((t_token*)(lst->content))->value);
		}
		else
		{
			if (op_index >= 0
				&& is_priority(op_stack[op_index], ((t_token*)(lst->content))->type) == TRUE)
				do_op(nb_stack, op_stack, &nb_index, &op_index);
			op_index++;
			op_stack[op_index] = ((t_token*)(lst->content))->type;
		}
		lst = lst->next;
	}
	do_op(nb_stack, op_stack, &nb_index, &op_index);
	res = nb_stack[0];
	return (res);
}
