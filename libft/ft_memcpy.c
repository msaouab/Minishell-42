/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:46:05 by mbelaman          #+#    #+#             */
/*   Updated: 2019/11/01 10:38:56 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*tmpsrc;
	char		*tmpdst;
	size_t		index;

	tmpsrc = (const char *)src;
	tmpdst = (char *)dst;
	index = 0;
	if (tmpsrc == NULL && tmpdst == NULL)
		return (NULL);
	while (index < n)
	{
		tmpdst[index] = tmpsrc[index];
		index++;
	}
	return ((void *)tmpdst);
}
