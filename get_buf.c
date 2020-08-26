/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_buf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:41:49 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/05 15:43:41 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fig		*get_buf(int fd1, char **line)
{
	char			buf[MAX_BUFF_SIZE + 1];
	int				b_w_reaad;

	if (!(fd1 < 0 || fd1 > 10240 || line == NULL))
	{
		b_w_reaad = read(fd1, buf, MAX_BUFF_SIZE);
		buf[b_w_reaad] = '\0';
		return (makefigurka(buf));
	}
	exit(0);
}
