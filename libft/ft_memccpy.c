/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:35:49 by mbelaman          #+#    #+#             */
/*   Updated: 2019/10/22 18:35:36 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*tmpdest;
	unsigned char	*tmpsrc;
	size_t			index;
	unsigned char	ch;

	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	ch = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		tmpdest[index] = tmpsrc[index];
		if (tmpsrc[index] == ch)
			return ((void *)(&tmpdest[index]) + 1);
		index++;
	}
	return (NULL);
}
