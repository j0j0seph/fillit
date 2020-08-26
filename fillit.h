/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 11:22:51 by fjessi            #+#    #+#             */
/*   Updated: 2019/12/10 23:51:29 by jojoseph         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 32
# define SIZE_LINE 5
# define MIN_BUFF_SIZE 19
# define MAX_BUFF_SIZE 545

int					check_charactar(int fd1);
int					check_tetrimer(char **str);
int					get_next_line(int fd, char **line);
int					write_massiv(int fd1);
int					write_str(int fd1, char **str);
void				str_free(char **str);
int					check_count_symbol(char **str);
int					check_count_touch(char **str);
int					free_str(char **str);

typedef struct		s_tetr
{
	int				i;
	int				j;
	int				c;
}					t_tetr;

typedef struct		s_massiv
{
	int				i;
	int				count_tetri;
	char			*line;
}					t_massiv;

typedef struct		s_square
{
	int				size;
	char			**str;
}					t_square;

t_square			*create_square(int size);
void				print_square(t_square *square);
void				free_square(t_square *square, int size);
int					size_square(int count_tetri);

typedef struct		s_fig
{
	int				x[4];
	int				y[4];
	char			letter;
	int				x_m;
	int				y_m;
	struct s_fig	*next;
}					t_fig;

t_fig				*makefigurka(char *buf);
t_fig				*makelist(char *buf);
t_fig				*get_buf(int fd1, char **line);
void				print_figurka(t_fig *head);
t_fig				*align(t_fig *list);
int					solve(t_fig *list, int count);
int					square_barriers(int size, t_fig *list, char axis);
int					symbol_barriers(t_fig *list, t_square *square);
void				element_name(t_fig *list, t_square *square, char letter);
void				full_free(t_fig *list);
int					finish(t_fig *list, int count);
int					to_be_continued(int ac, char **av);
int					true_file(int ac, char **av);
void				full_free(t_fig *list);

#endif
