/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:39:05 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/20 13:43:28 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//	check if there is a closed square
int	check_square(t_so_long *mygame)
{
	int	index;
	int	first_lwidth;

	first_lwidth = ft_strlen(mygame->map.map[0]);
	index = 1;
	while (index < mygame->img_height)
	{
		if ((int)ft_strlen(mygame->map.map[index]) != first_lwidth)
			return (0);
		index++;
	}
	return (1);
}

int	check_width(t_so_long *mygame)
{
	int	x;
	int	y;

	x = 0;
	while (x < mygame->img_height)
	{
		y = 0;
		while (mygame->map.map[x][y])
		{
			y++;
		}
		if (y != mygame->img_width)
			return (0);
		x++;
	}
	return (1);
}
