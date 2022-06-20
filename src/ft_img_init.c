/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:40:00 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/20 19:26:24 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_game.h"

void	ft_init_img(t_so_long *mygame)
{
	mygame->rel_path_path = "./img/floor.xpm";
	mygame->path = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_path,
			&mygame->i, &mygame->j);
	mygame->rel_path_wall = "./img/wall.xpm";
	mygame->wall = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_wall,
			&mygame->i, &mygame->j);
	mygame->rel_path_ply = "./img/player1.xpm";
	mygame->player = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_ply,
			&mygame->i, &mygame->j);
	mygame->rel_path_col = "./img/collect.xpm";
	mygame->collect = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_col,
			&mygame->i, &mygame->j);
	mygame->rel_path_exi = "./img/exit.xpm";
	mygame->exitus = mlx_xpm_file_to_image(mygame->mlx, mygame->rel_path_exi,
			&mygame->i, &mygame->j);
}

void	ft_setplayer(int jwidth, int iheight, t_so_long *mygame)
{
	mygame->myplayer.horizontal = jwidth;
	mygame->myplayer.vertical = iheight;
	ft_paintplayer(jwidth, iheight, mygame);
}

void	ft_setcollect(int jwidth, int iheight, t_so_long *mygame)
{
	mygame->colsum++;
	mygame->collectible++;
	ft_paint_collect(jwidth, iheight, mygame);
}
