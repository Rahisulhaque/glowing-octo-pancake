

#include "fillit.h"

char		**fill_grid(char **grid, char *buf)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < get_num_shapes(buf))
	{
		grid[j] = (char*)malloc(sizeof(char) * 20 + 1);
		if (grid[j] == NULL)
			return (NULL);
		while (k < 20)
		{
			grid[j][k] = buf[i];
			k++;
			i++;
		}
		grid[j][20] = '\0';
		k = 0;
		j++;
		i++;
	}
	grid[j] = NULL;
	return (grid);
}

char		**create_grid(char **grid, int square_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	grid = ft_memalloc(sizeof(char *) * square_size + 1);
	while (i < square_size)
	{
		grid[i] = ft_memalloc(sizeof(char) * square_size + 1);
		i++;
	}
	i = 0;
	while (j < square_size)
	{
		while (i < square_size)
		{
			grid[j][i++] = '.';
		}
		grid[j][i] = '\0';
		i = 0;
		j++;
	}
	grid[j] = NULL;
	return (grid);
}

t_shape		*new_grid(char **shape, int num)
{
	t_shape	*new;

	new = NULL;
	new = (t_shape *)malloc(sizeof(t_shape));
	if (new == NULL)
		return (NULL);
	new->shape = shape;
	new->letter = 'A' + num;
	new->x = 0;
	new->y = 0;
	new->next = NULL;
	return (new);
}

void		free_grid(char **grid, int grid_size)
{
	int i;

	i = 0;
	while (i < grid_size)
	{
		ft_strdel(&grid[i]);
		i++;
	}
	ft_strdel(grid);
}
