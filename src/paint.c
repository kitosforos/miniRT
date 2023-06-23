/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danicn <danicn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:12:24 by dcruz-na          #+#    #+#             */
/*   Updated: 2023/06/23 19:46:13 by danicn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "paint.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	paint_objects() 
{
	int x=x;
	return (0);
}

int close_window(int keycode, void *arg)
{
    // Realizar cualquier limpieza o liberación de recursos necesarios
	keycode = keycode;
	arg = arg;
    exit(0);
}

void	my_mlx_hooks(void *mlx_ptr, void *mlx_win) {
	mlx_hook(mlx_win, 17, 0, close_window, mlx_ptr);
	
	mlx_hook(mlx_win, 2, 0, close_window, mlx_ptr);
	return ;
}

int paint()
{
    void	*mlx_ptr;
	void	*win_ptr;
	t_data	data;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, RES_WIDTH, RES_HEIGHT, "mlx 42");
	my_mlx_hooks(mlx_ptr, win_ptr);
	data.img = mlx_new_image(mlx_ptr, RES_WIDTH, RES_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	paint_objects(&data);	
	mlx_put_image_to_window(mlx_ptr, win_ptr, data.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}