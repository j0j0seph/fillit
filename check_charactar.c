/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_charactar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:50:35 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/10 23:39:51 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_four_on_four(char *line)
{
	size_t		i;
	size_t		length;
	int			result;

	i = 0;
	length = ft_strlen(line);
	while ((line[i] == '.' || line[i] == '#') && line[i] != '\n' && length == 4)
		i++;
	if (length == i && length == 4)
		result = 1;
	else
		result = 0;
	return (result);
}

static int		check_five_line(char *line)
{
	size_t		length;
	int			result;

	length = ft_strlen(line);
	if (length == 0)
		result = 1;
	else
		result = 0;
	return (result);
}

int				check_charactar(int fd1)
{
	char	*line;
	int		count;
	int		result;

	count = 0;
	result = 1;
	while (get_next_line(fd1, &line) && result == 1)
	{
		if (count < 4)
		{
			result = check_four_on_four(line);
			free(line);
			count++;
		}
		else if (count == 4)
		{
			result = check_five_line(line);
			free(line);
			count = 0;
		}
	}
	if (count == 4)
		return (result);
	return (0);
}
