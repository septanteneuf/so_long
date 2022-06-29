/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:39:20 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/29 07:56:04 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_map
{
	char	**map;
}	t_map;

typedef struct s_player
{
	int		horizontal;
	int		vertical;
	t_map	map;

}	t_player;

typedef struct s_errors
{
	int		colcount;
	int		plycount;
	int		extcount;

}	t_errors;

typedef struct s_so_long
{
	t_map		map;
	t_player	myplayer;
	t_errors	maperrors;

	void		*mlx;
	void		*window;

	void		*path;
	void		*wall;
	void		*player;
	void		*collect;
	void		*exitus;

	int			collectible;
	int			colsum;

	int			steps;

	char		*rel_path_path;
	char		*rel_path_wall;
	char		*rel_path_ply;
	char		*rel_path_col;
	char		*rel_path_exi;

	int			img_width;
	int			img_height;
	int			i;
	int			j;

}	t_so_long;

//initializing the pictures
void	ft_init_img(t_so_long *mygame);
//setting the player coordinates
void	ft_setplayer(int jwidth, int iheight, t_so_long *mygame);
//setting and counting up the collectibles
void	ft_setcollect(int jwidth, int iheight, t_so_long *mygame);

//paiting functions
void	ft_paintwall(int x, int y, t_so_long *wall);
void	ft_paintpath(int x, int y, t_so_long *path);
void	ft_paintplayer(int x, int y, t_so_long *playerimg);
void	ft_paint_collect(int x, int y, t_so_long *collect);
void	ft_paintexit(int x, int y, t_so_long *exitus);

//for moving the player around
int		ft_playermove(int keycode, t_so_long *mygame);
void	up(t_so_long *mygame);
void	left(t_so_long *mygame);
void	bottom(t_so_long *mygame);
void	right(t_so_long *mygame);

//for updatiing the map
void	ft_updatemap(int x, int y, t_so_long *mypath);
void	ft_currentfield(int iheight, int jwidth, t_so_long *mygame);

//dealing with errors
void	ft_errors(t_so_long *mygame);
int		ft_checkmap_lu(t_so_long *mygame);
int		ft_checkmap_rd(t_so_long *mygame);
int		ft_checkmap_in(t_so_long *mygame);
int		ft_checkmin(t_so_long *mygame);
int		ft_checksquare(t_so_long *mygame);

//exit game
int		ft_exitgame(void);

//counting the collectible
void	ft_countcol(t_so_long *mygame);
void	ft_checkcol(t_so_long *mygame);

//so_long main
int		count_mapunit(char **argv);
void	ft_readmap(t_so_long *mygame, char **argv);
void	ft_map_base(t_so_long *mygame);
void	ft_paintmap(t_so_long *mygame);

#endif