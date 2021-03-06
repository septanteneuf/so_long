/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbourcy <bbourcy@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:28:02 by jzhou             #+#    #+#             */
/*   Updated: 2022/07/08 15:45:05 by bbourcy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index;
	char	*sub;

	index = 0;
	if (s == 0)
		return (0);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (sub == 0)
		return (0);
	if (start >= ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	while (index < len)
	{
		sub[index] = s[start + index];
		index++;
	}
	sub[index] = '\0';
	return (sub);
}
