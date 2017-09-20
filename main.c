

#include "fillit.h"

static void	print_sol(char **grid)
{
	int i;

	i = 0;
	while (grid[i] != NULL)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

t_shape		*split_blocks(char **grid)
{
	int			i;
	t_shape		*start;
	t_shape		*ptr;

	i = 1;
	start = NULL;
	ptr = NULL;
	start = new_grid(ft_strsplit(grid[0], '\n'), 0);
	ptr = start;
	while (i < g_num_shapes)
	{
		ptr->next = new_grid(ft_strsplit(grid[i], '\n'), i);
		ptr = ptr->next;
		i++;
	}
	ptr->next = NULL;
	return (start);
}

static int	min_size(char **tetros)
{
	int		i;
	int		size;

	i = 0;
	size = 2;
	while (tetros[i])
	{
		i++;
	}
	while (4 * i > size * size)
		size++;
	return (size);
}

char		**read_stdin(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	**tmp;
	int		i;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	ret = 1;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		buf[ret] = '\0';
	g_num_shapes = get_num_shapes(buf);
	tmp = (char**)malloc(sizeof(char *) * get_num_shapes(buf) + 1);
	if (tmp == NULL)
		return (NULL);
	if (first_test(buf) == 0)
		return (NULL);
	tmp = fill_grid(tmp, buf);
	i = 0;
	return (tmp);
}

int			main(int argc, char **argv)
{
	t_shape		*start;
	char		**grid;

	start = NULL;
	grid = NULL;
	if (argc != 2)
	{
		ft_usage();
		return (-1);
	}
	if ((grid = read_stdin(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	if (check_grid(grid) == 0)
	{
		ft_putendl("error");
		free_grid(grid, g_num_shapes + 1);
		return (-1);
	}
	start = split_blocks(grid);
	free_grid(grid, g_num_shapes + 1);
	print_sol(solve(start, min_size(grid), NULL));
	return (0);
}
