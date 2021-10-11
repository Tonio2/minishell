/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:12:15 by alabalet          #+#    #+#             */
/*   Updated: 2021/10/11 17:12:36 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_exit_code(t_vars *v)
{
	int	cpt;

	cpt = -1;
	while (++cpt < v->nb_cmd)
		waitpid(v->cmd[cpt].pid, &(v->cmd[cpt].exit_code), 0);
	if (g_sig.exit_code == 130)
		return (130);
	if (g_sig.exit_code == 131)
		return (131);
	return (WEXITSTATUS(v->cmd[cpt - 1].exit_code));
}
