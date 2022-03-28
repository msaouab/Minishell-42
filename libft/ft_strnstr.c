/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:21:03 by mbelaman          #+#    #+#             */
/*   Updated: 2021/04/26 15:14:02 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	pos;
	size_t	i;

	pos = 0;
	i = 1;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[pos] != '\0')
	{
		if (str[pos] == to_find[0] && pos + i <= len)
		{
			while (to_find[i] != '\0' && str[pos + i] == to_find[i]
				&& pos + i <= len)
				i++;
			if (to_find[i] == '\0')
				return ((char *)&str[pos]);
		}
		pos++;
	}
	return (0);
}
