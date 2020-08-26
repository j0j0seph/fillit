/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:36:26 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/11 20:31:10 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				square_barriers(int size, t_fig *list, char axis)
{
	if (axis == 'x')
		return ((list->x[0] + list->x_m < size) &&
			(list->x[1] + list->x_m < size) &&
			(list->x[2] + list->x_m < size) &&
			(list->x[3] + list->x_m < size));
	else
		return ((list->y[0] + list->y_m < size) &&
			(list->y[1] + list->y_m < size) &&
			(list->y[2] + list->y_m < size) &&
			(list->y[3] + list->y_m < size));
}

int				symbol_barriers(t_fig *list, t_square *square)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = list->x[i] + list->x_m;
	y = list->y[i] + list->y_m;
	while (i <= 3 && square->str[y][x] == '.')
	{
		i++;
		x = list->x[i] + list->x_m;
		y = list->y[i] + list->y_m;
	}
	return (i);
}

void			element_name(t_fig *list, t_square *square, char letter)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i <= 3)
	{
		x = list->x[i] + list->x_m;
		y = list->y[i] + list->y_m;
		square->str[y][x] = letter;
		i++;
	}
}

static int		fill_square(int size, t_fig *list, t_square *square)
{
	if (!list)
		return (1);
	list->x_m = 0;
	list->y_m = 0;
	while (square_barriers(size, list, 'y'))
	{
		while (square_barriers(size, list, 'x'))
		{
			if ((symbol_barriers(list, square)) == 4)
			{
				element_name(list, square, list->letter);
				if (fill_square(size, list->next, square))
					return (1);
				else
					element_name(list, square, '.');
			}
			list->x_m++;
		}
		list->x_m = 0;
		list->y_m++;
	}
	return (0);
}

int				solve(t_fig *list, int count)
{
	t_square	*square;
	int			size;

	size = size_square(count);
	if (size == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!(square = create_square(size)))
		return (1);
	while (!(fill_square(size, list, square)))
	{
		free_square(square, size);
		size++;
		if (!(square = create_square(size)))
			return (1);
	}
	print_square(square);
	free_square(square, size);
	return (0);
}
