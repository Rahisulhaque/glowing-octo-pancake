/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 10:20:59 by alcornea          #+#    #+#             */
/*   Updated: 2017/02/26 19:09:42 by aabdrash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

# include "libft.h"

int g_num_shapes;
# define BUFF_SIZE 4096

typedef struct			s_shape
{
	char				**shape;
	char				letter;
	int					x;
	int					y;
	struct s_shape		*next;
}						t_shape;

t_shape					*position_arrange(t_shape *start);
t_shape					*splittab(char **grid);
t_shape					*new_grid(char **shape, int num);
char					**solve(t_shape *start, int square_size,\
		char **sol_grid);
char					**read_stdin(char *argv);
char					**create_grid(char **grid, int square_size);
int						get_num_shapes(char *grid);
int						check_grid(char **grid);
int						check_shape(char *grid);
int						check_line(char *grid);
int						height_block(char *grid);
int						width_block(char *grid);
int						is_alone(char *grid);
int						check_void_int(char *grid);
int						first_test(char *buf);
void					free_grid(char **grid, int tab_size);
void					ft_usage(void);
char					**fill_grid(char **grid, char *buf);

#endif
