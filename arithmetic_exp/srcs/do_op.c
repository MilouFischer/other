#include "libft.h"
#include "shell.h"

void	do_add(long long *nb_stack, ssize_t *nb_index)
{
	long long	nb1;
	long long	nb2;

	nb2 = nb_stack[*nb_index];
	(*nb_index)--;
	nb1 = nb_stack[*nb_index];
	nb_stack[*nb_index] = nb1 + nb2;
}

void	do_sub(long long *nb_stack, ssize_t *nb_index)
{
	long long	nb1;
	long long	nb2;

	nb2 = nb_stack[*nb_index];
	(*nb_index)--;
	nb1 = nb_stack[*nb_index];
	nb_stack[*nb_index] = nb1 - nb2;
}

void	do_mult(long long *nb_stack, ssize_t *nb_index)
{
	long long	nb1;
	long long	nb2;

	nb2 = nb_stack[*nb_index];
	(*nb_index)--;
	nb1 = nb_stack[*nb_index];
	nb_stack[*nb_index] = nb1 * nb2;
}

void	do_div(long long *nb_stack, ssize_t *nb_index)
{
	long long	nb1;
	long long	nb2;

	nb2 = nb_stack[*nb_index];
	(*nb_index)--;
	nb1 = nb_stack[*nb_index];
	if (nb2 == 0)
	{
		nb_stack[*nb_index] = 0;
		ft_putendl_fd("Attempt to divide by 0", 2);
	}
	nb_stack[*nb_index] = nb1 / nb2;
}

void	do_mod(long long *nb_stack, ssize_t *nb_index)
{
	long long	nb1;
	long long	nb2;

	nb2 = nb_stack[*nb_index];
	(*nb_index)--;
	nb1 = nb_stack[*nb_index];
	nb_stack[*nb_index] = nb1 % nb2;
}
