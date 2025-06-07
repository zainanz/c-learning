/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:48:08 by zali              #+#    #+#             */
/*   Updated: 2025/05/20 09:48:26 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "minilibx/mlx.h"
#include <X11/keysym.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

typedef struct pos
{
	int	x;
	int	y;
}	t_pos;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
t_pos	*pos_init()
{
	static t_pos pos;
	return (&pos);
}
void	update_rect(void *ptr)
{
	int			i,j;
	t_mlx_data	*data;

	data = (t_mlx_data *)ptr;
	i = 0;
	j = 0;
	while (i < 200)
	{
		j = 0;
		while (j < 200)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, pos_init()->x + i, pos_init()->y + j, 0xff0000);
			j++;
		}
		i++;
	}
}
int	handle_input(int keycode, void *data)
{
	t_pos	*pos = pos_init();

	if (keycode == XK_Down)
	{
		pos->y += 50;
		update_rect(data);
		printf("Pressed downkey.\n");
	}
	printf("Pressed keycode: %i.\n", keycode);
	return (1);
}
int	main(void)
{
	t_mlx_data	data;
	t_pos		*pos;

	pos = pos_init();
	pos->x = 0;
	pos->y = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 600, "Hello world!");
	mlx_key_hook(data.win_ptr, handle_input, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
