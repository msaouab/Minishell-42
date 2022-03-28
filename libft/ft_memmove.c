/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 08:36:31 by mbelaman          #+#    #+#             */
/*   Updated: 2019/11/01 14:48:11 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmpdst;
	const char	*tmpsrc;
	const char	*lensrc;
	char		*lendst;

	tmpdst = (char *)dst;
	tmpsrc = (const char *)src;
	if (tmpdst == NULL && tmpsrc == NULL)
		return (NULL);
	if (tmpdst < tmpsrc)
	{
		while (len-- != '\0')
			*tmpdst++ = *tmpsrc++;
	}
	else
	{
		lensrc = tmpsrc + (len - 1);
		lendst = tmpdst + (len - 1);
		while (len-- != '\0')
			*lendst-- = *lensrc--;
	}
	return (dst);
}
