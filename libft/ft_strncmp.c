/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:14:55 by mbelaman          #+#    #+#             */
/*   Updated: 2021/04/26 15:13:24 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			index;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (str1[index] != '\0' && str2[index] != '\0' && index < n)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
		index++;
	}
	if (index < n && ((str1[index] != '\0' && str2[index] == '\0')
			|| (str1[index] == '\0' && str2[index] != '\0')))
		return (str1[index] - str2[index]);
	return (0);
}
