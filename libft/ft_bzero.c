/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:07:11 by mbelaman          #+#    #+#             */
/*   Updated: 2019/11/01 10:29:46 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*tmp;
	size_t	index;

	tmp = (char *)str;
	index = 0;
	while (index < n)
	{
		tmp[index] = 0;
		index++;
	}
}
