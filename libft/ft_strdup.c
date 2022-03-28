/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:59:30 by mbelaman          #+#    #+#             */
/*   Updated: 2019/10/27 19:28:37 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*string;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	string = (char *)malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < len)
	{
		string[i] = src[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}
