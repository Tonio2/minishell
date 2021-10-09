/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:55:19 by alabalet          #+#    #+#             */
/*   Updated: 2021/10/09 20:16:00 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *str, int mode)
{
	if (mode == 0 || mode == 1 || mode == 2)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(str, 2);
		if (mode == 0)
			ft_putstr_fd(": command not found\n", 2);
		else if (mode == 1)
			ft_putstr_fd(": No such file or directory\n", 2);
		else if (mode == 2)
			ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (mode == 3)
		ft_putstr_fd(str, 2);
	if (mode == 4)
		ft_putstr_fd("minishell : unexpected end of line");
	if (mode == 5)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(str || "newline", 2);
		ft_putstr_fd("\n", 2);
	}
}
