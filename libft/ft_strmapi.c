/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:10:06 by mbelaman          #+#    #+#             */
/*   Updated: 2021/04/26 15:12:44 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		len;
	int		index;

	index = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tmp == NULL)
		return (NULL);
	while (index < len)
	{
		tmp[index] = f(index, s[index]);
		index++;
	}
	tmp[index] = '\0';
	return (tmp);
}
