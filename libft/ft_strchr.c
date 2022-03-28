/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 16:31:56 by mbelaman          #+#    #+#             */
/*   Updated: 2019/11/09 15:48:34 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	ch;

	index = 0;
	ch = (char)c;
	while (s[index] && s[index] != ch)
		index++;
	if (s[index] == ch)
		return ((char *)&s[index]);
	else
		return (NULL);
}
