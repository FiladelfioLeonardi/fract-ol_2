/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:00:11 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/18 02:38:45 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800

//COLORS
#define BLACK 		0x000000
#define CRIMSON 	0xDC143C
#define GOLD 		0xFFD700
#define TEAL 		0x008080
#define WHITE		0xFFFFFF

//LOCAL LIBRARIES
# include "./minilibx-linux/mlx.h"  //linux lib for mlx

//STRUCTS
typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;

	t_img	img;
	
	//HOOK MEMBER VARIABLES
	double escape_value;
	
	int		iterations_definition;
	double	shift_x;
	double 	shift_y;
	double 	zoom;

} t_fractol;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
}	t_img;

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

//UTILS FUNCTIONS
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);

//FRACTOL FUNCT
void	fractol_init(t_fractol *fractol);
void 	fractol_render(t_fractol *fractol);

//SCALE MAP
double	map(double unscaled_num, double new_min, double new_max,
		double old_min, double old_max);
t_complex  sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

#endif