/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 22:19:38 by jojoseph          #+#    #+#             */
/*   Updated: 2019/12/12 23:32:02 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	full_free(t_fig *list)
{
	t_fig *tmp;

	if (list == NULL)
		return ;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

int		finish(t_fig *list, int count)
{
	if (list == NULL)
	{
		write(1, "error\n", 6);
		return (0);
	}
	else
	{
		solve(list, count);
		full_free(list);
		return (0);
	}
}

int		to_be_continued(int ac, char **av)
{
	int		fd1;
	t_fig	*list;
	char	*line;
	int		count;

	if (ac == 2)
	{
		fd1 = open(av[1], O_RDONLY);
		count = write_massiv(fd1);
		close(fd1);
		if (count == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		fd1 = open(av[1], O_RDONLY);
		list = get_buf(fd1, &line);
		close(fd1);
		finish(list, count);
	}
	return (0);
}

int		true_file(int ac, char **av)
{
	int		fd1;
	int		check;

	fd1 = open(av[1], O_RDONLY);
	if (fd1 < 0 || fd1 > 10240)
	{
		write(1, "error\n", 6);
		return (0);
	}
	else
	{
		check = check_charactar(fd1);
		close(fd1);
		if (check == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		else
			to_be_continued(ac, av);
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "Usage: ./fillit file_name\n", 26);
		return (0);
	}
	else
		true_file(ac, av);
}
