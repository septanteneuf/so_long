/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:38:58 by bbourcy           #+#    #+#             */
/*   Updated: 2022/07/20 11:53:59 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkmap_lu(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	while (height < mygame->img_height)
	{
		if (mygame->map.map[height][width] != '1')
			return (0);
		height++;
	}
	height = 0;
	width = 0;
	while (width < mygame->img_width)
	{
		if (mygame->map.map[height][width] != '1')
			return (0);
		width++;
	}
	return (1);
}

int	test(t_so_long *mygame)
{
	int	x;
	int	y;

	x = 0;
	while(x < mygame->img_height)
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

int	checkmap_rd(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = mygame->img_width - 1;
	while (height < mygame->img_height)
	{
		if (mygame->map.map[height][width] != '1')
			return (0);
		height++;
	}
	height = mygame->img_height - 1;
	width = 0;
	while (width < mygame->img_width)
	{
		if (mygame->map.map[height][width] != '1')
			return (0);
		width++;
	}
	return (1);
}

int	checkmap_in(t_so_long *mygame)
{
	int		height;
	int		width;
	char	c;

	height = 0;
	width = 0;
	while (height < mygame->img_height)
	{
		while (width < mygame->img_width)
		{
			c = mygame->map.map[height][width];
			if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E')
				return (0);
			width++;
		}
		height++;
		width = 0;
	}
	return (1);
}

int	check_min(t_so_long *mygame)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	mygame->maperrors.colcount = 0;
	mygame->maperrors.extcount = 0;
	while (height < mygame->img_height)
	{
		while (width < mygame->img_width)
		{
			if (mygame->map.map[height][width] == 'P')
				mygame->maperrors.plycount = 1;
			else if (mygame->map.map[height][width] == 'C')
				mygame->maperrors.colcount++;
			else if (mygame->map.map[height][width] == 'E')
				mygame->maperrors.extcount++;
			width++;
		}
		height++;
		width = 0;
	}
	if (mygame->maperrors.plycount < 1 || mygame->maperrors.colcount < 1
		|| mygame->maperrors.extcount < 1)
		return (0);
	else
		return (1);
}

void	errors(t_so_long *mygame)
{
	if(!test(mygame))
		exit_game("Wrong width", mygame);
	if (!check_min(mygame))
		exit_game("Missing element", mygame);
	if (!checkmap_lu(mygame))
		exit_game("Wrong wall pos", mygame);
	if(!checkmap_rd(mygame))
		exit_game("Wrong wall pos (also)", mygame);
	if (!checkmap_in(mygame))
		exit_game("Wrong walls/other", mygame);
	if (!check_square(mygame))
		exit_game("Map isn't rectangular", mygame);
}
