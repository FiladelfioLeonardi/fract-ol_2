/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 22:33:19 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/17 18:10:44 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char	**argv)
{
	t_fractol	fractol;
	
	if ((argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
		||	(argc == 4 && ft_strcmp(argv[1], "julia") == 0))
	{
		fractol.name = argv[1];
		if (ft_strcmp(argv[1], "julia") == 0) 
		{
			//...
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr_fd("Usage: ./fractol mandelbrot\n", 2);
		ft_putstr_fd("Usage: ./fractol julia [real] [imaginary]\n", 2);
		return (EXIT_FAILURE);
	}

}