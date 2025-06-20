/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:19:17 by gmorelli          #+#    #+#             */
/*   Updated: 2022/10/10 15:35:47 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*x;
	int		y;

	x = (char *) str;
	y = ft_strlen(x);
	while (y >= 0)
	{
		if (x[y] == c)
		{
			return (&x[y]);
		}
		y--;
	}
	return (0);
}
