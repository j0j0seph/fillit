/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojoseph <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 23:54:07 by jojoseph          #+#    #+#             */
/*   Updated: 2019/12/10 23:56:21 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_square	*create_square(int size)
{
	int			i;
	t_square	*square;

	i = 0;
	if (!(square = (t_square *)ft_memalloc(sizeof(t_square))))
		return (NULL);
	square->size = size;
	if (!(square->str = (char **)ft_memalloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		if ((square->str[i] = ft_strnew(size)))
			ft_memset(square->str[i], '.', size);
		else
		{
			while (--i)
				ft_strdel((char **)&square[i]);
			free(square);
			return (NULL);
		}
		i++;
	}
	return (square);
}

void		print_square(t_square *square)
{
	int		i;

	i = 0;
	while (i < square->size)
		ft_putendl(square->str[i++]);
}

void		free_square(t_square *square, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_strdel((char **)&(square->str[i]));
		i++;
	}
	ft_strdel((char **)&(square->str));
	ft_strdel((char **)&square);
}

int			size_square(int count_tetri)
{
	int		size;
	int		k;

	if (count_tetri <= 0 || count_tetri > 26)
		return (0);
	k = (4 * count_tetri);
	size = 0;
	while (size * size < k)
		size++;
	return (size);
}
