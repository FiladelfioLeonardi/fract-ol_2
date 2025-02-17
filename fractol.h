/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:00:11 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/17 18:12:44 by fileonar         ###   ########.fr       */
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

# define WIDTH 800
# define HEIGHT 800

//UTILS FUNCTIONS
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *s);
void	ft_putstr_fd(char *s, int fd);

//FRACTOL FUNCT
void	fractol_init(t_fractol *fractol);
