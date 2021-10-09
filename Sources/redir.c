/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:08:25 by alabalet          #+#    #+#             */
/*   Updated: 2021/10/10 01:34:25 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_left(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		print_error(str, 1);
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

void	redir_right(t_token tkn)
{
	int	fd;

	fd = open(tkn.str, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void	redir_rright(t_token tkn)
{
	int	fd;

	fd = open(tkn.str, O_WRONLY | O_CREAT | O_APPEND, 0644);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

int	redir(t_token *redir_tab)
{
	int	cpt;
	int	ret;

	cpt = -1;
	while (redir_tab[++cpt].type)
	{
		if (redir_tab[cpt].type == LEFT)
			ret = redir_left(redir_tab[cpt].str));
		if (tkn.type == RIGHT)
			redir_right(redir_tab[cpt].str);
		if (tkn.type == RRIGHT)
			redir_rright(redir_tab[cpt].str);
		if (ret)
			return (ret);
	}
}
