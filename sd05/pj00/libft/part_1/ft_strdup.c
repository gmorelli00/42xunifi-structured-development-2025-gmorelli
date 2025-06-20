/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 09:50:04 by gmorelli          #+#    #+#             */
/*   Updated: 2022/10/11 10:47:51 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	int		l;
	int		x;

	x = 0;
	l = ft_strlen(s);
	d = (char *) malloc(sizeof(*d) * (l + 1));
	while (x < l)
	{
		d[x] = s[x];
		x++;
	}
	d[x] = '\0';
	return (d);
}
