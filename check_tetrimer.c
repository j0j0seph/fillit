/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetrimer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:59:50 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/11 20:34:22 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_str(char **str)
{
	if (!str)
		return (0);
	ft_free(str);
	return (0);
}

int		check_tetrimer(char **str)
{
	int		k;
	int		c;

	c = 0;
	k = check_count_symbol(str);
	if (k == 4)
		c = check_count_touch(str);
	if (k == 4 && c >= 6)
		return (1);
	else
		return (0);
}

void	str_free(char **str)
{
	int		i;

	i = 0;
	while (i < 4)
		free(str[i++]);
}

int		write_str(int fd1, char **str)
{
	t_massiv	m;

	m.count_tetri = 0;
	while ((get_next_line(fd1, &m.line)))
	{
		m.i = 0;
		while (m.i < 4)
		{
			if ((str[m.i++] = ft_strsub(m.line, 0, 4)) == NULL)
				free_str(str);
			free(m.line);
			get_next_line(fd1, &m.line);
		}
		if ((m.i % 4 == 0) && (ft_strcmp(m.line, "\n") == -10))
			free(m.line);
		if (check_tetrimer(str) == 0)
		{
			free_str(str);
			return (0);
		}
		m.count_tetri++;
		str_free(str);
	}
	free(str);
	return (m.count_tetri);
}

int		write_massiv(int fd1)
{
	char	**str;
	int		res;

	res = 0;
	if ((str = (char**)malloc(sizeof(char*) * 4)) == NULL)
		return (0);
	res = write_str(fd1, str);
	return (res);
}
