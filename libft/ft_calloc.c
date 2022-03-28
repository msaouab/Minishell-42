/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:52:50 by mbelaman          #+#    #+#             */
/*   Updated: 2019/10/23 11:41:59 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	index;
	size_t	len;

	index = 0;
	len = count * size;
	ptr = malloc(len);
	if (ptr == NULL)
		return (NULL);
	while (index < len)
	{
		ptr[index] = '\0';
		index++;
	}
	return ((void *)ptr);
}
