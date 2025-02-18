/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:20:12 by fileonar          #+#    #+#             */
/*   Updated: 2025/02/18 10:23:38 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL && fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 != '\0' && *s2 != '\0')
	{	
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

double	atodbl(char	*s)
{
	long	int_part;
	double	fractional_part;
	double	pow;
	int		sign;
	
	int_part = 0;
	fractional_part = 0;
	sign = 1;
	pow = 1;

	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v' || *s == '\f'
		|| *s == '\r')
		s++;
	while (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign *= -1;
		else
			s++;
	}
	while (*s != '.' && *s)
		int_part = (int_part * 10) + (*s++ - '0');
	if (*s == '.') 
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - '0') * pow;
	}
	return ((int_part + fractional_part) * sign);
}
