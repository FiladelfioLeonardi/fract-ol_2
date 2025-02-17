/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:00:11 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/17 20:01:41 by fileonar         ###   ########.fr       */
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


# define WIDTH 800
# define HEIGHT 800

//UTILS FUNCTIONS
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);

//FRACTOL FUNCT
void	fractol_init(t_fractol *fractol);


#endif