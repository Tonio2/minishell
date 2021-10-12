/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <alabalet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:33:46 by alabalet          #+#    #+#             */
/*   Updated: 2021/01/24 11:36:40 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../Includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s++, 1);
	}
}
