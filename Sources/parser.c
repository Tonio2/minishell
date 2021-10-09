/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 01:32:15 by alabalet          #+#    #+#             */
/*   Updated: 2021/10/10 01:51:07 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parser(t_vars *v)
{
	int	i_cmd;
	int	i_tkn;

	v->nb_cmd = 1;
	i_cmd = -1;
	while (v->tkn_tab[++i_cmd].type)
		if (v->tkn_tab[i_cmd].type == PIPE)
			v->nb_cmd++;
	v->cmd = malloc(v->nb_cmd * sizeof(t_cmd));
	i_cmd = -1;
	i_tkn = 0;
	while (++i_cmd < v->nb_cmd)
	{
		v->cmd[i_cmd] = ft_parse_token(v->tkn_tab, &i_tkn);
		if (v->cmd[i_cmd].av[0])
			v->cmd[i_cmd].path = get_cmd_path(v, v->cmd[i_cmd].av[0]);
	}
}
