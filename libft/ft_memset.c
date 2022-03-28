/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:27:37 by mbelaman          #+#    #+#             */
/*   Updated: 2019/10/30 16:50:01 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*tmp;
	size_t			index;
	unsigned char	ch;

	index = 0;
	tmp = (char *)b;
	ch = (unsigned char)c;
	while (index < len)
	{
		tmp[index] = ch;
		index++;
	}
	return (b);
}
