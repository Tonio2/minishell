/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:14:35 by alabalet          #+#    #+#             */
/*   Updated: 2021/10/09 20:07:23 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	line_status(char *line)
{
	int		i;
	char	quote;
	int		last_ch_is_pipe;

	if (!*line)
		return (1);
	i = -1;
	quote = 0;
	while (str[++i])
	{
		if (str[i] == '\'' || str[i] == '"')
			quote = str[i] * (quote == 0) + quote * (str[i] != quote);
		if (str[i] == '|')
			last_ch_is_pipe = 1;
		else if (str[i] != ' ')
			last_ch_is_pipe = 0;
	}
	if (quote == 0 && last_ch_is_pipe == 0)
	{
		print_error(0, 4);
		return (258);
	}
	return (0);
}

int	launch(t_vars *v, char *line)
{
	int		ret;
	char	*tmp;

	tmp = line;
	line = ft_strtrim(line, " ");
	free(tmp);
	ret = line_status(line);
	if (ret == 1)
		return (g_sig.exit_code);
	if (ret)
		return (ret);
	add_history(line);
	ret = lexer(v, line);
	if (ret)
		return (ret);
	ret = tokenize(v);
	if (ret)
		return (ret);
	parser(v);
	return (exec(v));
}

int	main(int ac, char **av, char **e)
{
	t_vars	v;
	char	*line;

	(void)av;
	if (ac != 1)
	{
		print_error("Usage : ./minishell");
		return (1);
	}
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	init_vars(&v, e);
	while (1)
	{
		echo_control_seq(0);
		g_sig.status = 0;
		line = readline("minishell> ");
		g_sig.status = 1;
		g_sig.exit_code = launch(v, line);
	}
	return (g_sig.exit_code);
}
