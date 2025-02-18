/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 10:33:24 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/18 02:36:09 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void my_pixel_put(int x, int y, t_img *img, int color)
{
	int offset;
	
	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			color;

	i = 0;

	z.real = (map(x, -2, 2, 0, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.imaginary = (map(y, 2, -2, 0, HEIGHT) * fractol->zoom) + fractol->shift_y;

	while(i < fractol->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > 
			fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, 0, fractol->iterations_definition);
			my_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, BLACK);
}

void 	fractol_render(t_fractol *fractol)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
			handle_pixel(x, y, fractol);
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
							fractol->img.img_ptr, 0, 0);

}
