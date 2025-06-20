/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:16:15 by gmorelli          #+#    #+#             */
/*   Updated: 2022/10/11 09:40:27 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t num, size_t dim)
{
	void		*ptr;
	char		*d;
	size_t		x;

	ptr = malloc(num * dim);
	if (ptr == 0)
		return (0);
	d = (char *)ptr;
	x = 0;
	while (x < dim * num)
	{
		d[x] = '\0';
		x++;
	}
	return (ptr);
}
