/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:08:04 by gmorelli          #+#    #+#             */
/*   Updated: 2022/10/10 15:30:48 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dt;
	const char	*sr;
	size_t		x;

	dt = dest;
	sr = src;
	x = 0;
	while (x < n)
	{
		dt[x] = sr[x];
		x++;
	}
	return (dest);
}
