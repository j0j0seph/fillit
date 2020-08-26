/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:25:38 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/05 14:34:54 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		align_x(t_fig *list)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		list->x[i] -= 1;
		i++;
	}
}

static void		align_y(t_fig *list)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		list->y[i] -= 1;
		i++;
	}
}

t_fig			*align(t_fig *list)
{
	while ((list->x[0] != 0) &&
			(list->x[1] != 0) &&
			(list->x[2] != 0) &&
			(list->x[3] != 0))
		align_x(list);
	while ((list->y[0] != 0) &&
			(list->y[1] != 0) &&
			(list->y[2] != 0) &&
			(list->y[3] != 0))
		align_y(list);
	return (list);
}
