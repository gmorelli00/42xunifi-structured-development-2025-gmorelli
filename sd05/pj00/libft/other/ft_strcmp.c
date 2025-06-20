/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:19:48 by gmorelli          #+#    #+#             */
/*   Updated: 2023/05/03 12:19:52 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	x;
	int	check;

	x = 0;
	check = 0;
	while (str1[x] != '\0' && check == 0)
	{
		if (str1[x] == str2[x])
			x++;
		else if (str1[x] < str2[x])
			check = -1;
		else if (str1[x] > str2[x])
			check = 1;
	}
	return (check);
}
