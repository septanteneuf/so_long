/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorsquare.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:39:05 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/20 19:26:11 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_game.h"

int	ft_checksquare(t_so_long *mygame)
{
	int	index;
	int	first_lwidth;

	first_lwidth = ft_strlen(mygame->map.map[0]);
	index = 1;
	while (index < mygame->img_height)
	{
		if ((int)ft_strlen(mygame->map.map[index]) != first_lwidth)
			return (-1);
		index++;
	}
	return (0);
}
