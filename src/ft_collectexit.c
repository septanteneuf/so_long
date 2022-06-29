/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collectexit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:37:49 by bbourcy           #+#    #+#             */
/*   Updated: 2022/06/29 07:53:39 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_countcol(t_so_long *mygame)
{
	int	screencol;

	mygame->collectible--;
	screencol = mygame->colsum - mygame->collectible;
}

void	ft_checkcol(t_so_long *mygame)
{
	if (mygame->collectible == 0)
	{
		exit (0);
	}
}
