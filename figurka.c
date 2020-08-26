/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figurka.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:39:49 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/10 23:52:43 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fig	*makelist(char *buf)
{
	int		i;
	int		j;
	t_fig	*list;

	if (!(list = (t_fig *)malloc(sizeof(t_fig))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			list->x[j] = i % 5;
			list->y[j] = i / 5;
			j++;
		}
		i++;
	}
	list->x_m = 0;
	list->y_m = 0;
	list->next = NULL;
	return (align(list));
}

t_fig	*makefigurka(char *buf)
{
	t_fig	*head;
	t_fig	*list;
	size_t	i;
	char	letter;

	i = 0;
	letter = 'A';
	if (!(head = makelist(&buf[i])))
		return (NULL);
	head->letter = letter++;
	list = head;
	i = 21;
	while (i < ft_strlen(buf))
	{
		if (!(list->next = makelist(&buf[i])))
		{
			full_free(head);
			return (NULL);
		}
		list = list->next;
		list->letter = letter++;
		i += 21;
	}
	return (head);
}

void	print_figurka(t_fig *head)
{
	t_fig	*new;

	new = head;
	while (new)
	{
		ft_putchar(new->letter);
		new = new->next;
	}
}
