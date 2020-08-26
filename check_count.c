/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:57:41 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/05 14:59:23 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_last_line(char **str)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 3;
	j = 0;
	while (i == 3 && str[i][j] != '\0')
	{
		while (str[i][j] != '#' && str[i][j] != '\0')
			j++;
		while (str[i][j] == '#')
		{
			if (str[i][j + 1] == '#')
				c++;
			if (str[i][j - 1] == '#')
				c++;
			if (str[i - 1][j] == '#')
				c++;
			j++;
		}
	}
	return (c);
}

static int		check_middle_line(char **str)
{
	t_tetr	l;

	l.i = 1;
	l.j = 0;
	l.c = 0;
	while ((l.i == 2 || l.i == 1) && str[l.i][l.j] != '\0')
	{
		while (str[l.i][l.j] != '#' && str[l.i][l.j] != '\0')
			l.j++;
		while (str[l.i][l.j] == '#')
		{
			if (str[l.i][l.j + 1] == '#')
				l.c++;
			if (str[l.i][l.j - 1] == '#')
				l.c++;
			if (str[l.i - 1][l.j] == '#')
				l.c++;
			if (str[l.i + 1][l.j] == '#')
				l.c++;
			l.j++;
		}
		l.i++;
		l.j = 0;
	}
	return (l.c);
}

static int		check_first_line(char **str)
{
	int		i;
	int		j;
	int		c;

	c = 0;
	i = 0;
	j = 0;
	while (i == 0 && str[i][j] != '\0')
	{
		while (str[i][j] != '#' && str[i][j] != '\0')
			j++;
		while (str[i][j] == '#')
		{
			if (str[i][j + 1] == '#')
				c++;
			if (str[i][j - 1] == '#')
				c++;
			if (str[i + 1][j] == '#')
				c++;
			j++;
		}
	}
	return (c);
}

int				check_count_touch(char **str)
{
	t_tetr	l;

	l.i = 0;
	l.j = 0;
	l.c = 0;
	while (l.i < 4 && str[l.i][l.j] != '\0')
	{
		while (l.i == 0 && str[l.i][l.j] != '\0')
		{
			l.c = check_first_line(str);
			l.i++;
		}
		while (l.i == 2 || l.i == 1)
		{
			l.c = l.c + check_middle_line(str);
			l.i = 3;
		}
		while (l.i == 3)
		{
			l.c = l.c + check_last_line(str);
			l.i++;
		}
	}
	return (l.c);
}

int				check_count_symbol(char **str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 4)
	{
		while (str[i][j] != '#' && str[i][j] != '\0')
			j++;
		if (str[i][j] == '#')
		{
			k++;
			j++;
		}
		if (str[i][j] == '\0')
		{
			i++;
			j = 0;
		}
	}
	return (k);
}
