/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:22:38 by fjessi            #+#    #+#             */
/*   Updated: 2019/10/12 21:33:39 by fjessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		ft_get_line(char **s, char **line)
{
	char			*tmp;
	int				len;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&(*s)[len + 1]);
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char		*s[10240];
	char			buf[BUFF_SIZE + 1];
	int				b_w_reaad;
	char			*tmp;

	if (fd < 0 || fd > 10240 || line == NULL)
		return (-1);
	while ((b_w_reaad = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[b_w_reaad] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (b_w_reaad < 0)
		return (-1);
	else if (b_w_reaad == 0 && s[fd] == NULL)
		return (0);
	return (ft_get_line(&s[fd], line));
}
