/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 17:45:55 by mbelaman          #+#    #+#             */
/*   Updated: 2019/11/09 15:49:16 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;
	char	ch;

	index = 0;
	ch = (char)c;
	while (s[index])
		index++;
	while (s[index] != ch && index > 0)
		index--;
	if (s[index] == ch)
		return ((char *)&s[index]);
	else
		return (NULL);
}
