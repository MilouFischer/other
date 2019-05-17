/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 12:45:22 by efischer          #+#    #+#             */
/*   Updated: 2019/05/14 14:01:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

typedef	struct		s_dir
{
	const char		*name;
	const char		*type;
	const char		*mode;
	const char		*uid;
	const char		*gid;
	const char		*time;
	long int		link;
	long long int	size;
}					t_dir;

#endif
