/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:22:32 by mbelaman          #+#    #+#             */
/*   Updated: 2021/04/26 15:05:54 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lennb(long nb)
{
	int		digit;

	digit = 0;
	if (nb == 0)
		digit++;
	if (nb < 0)
	{
		nb = nb * -1;
		digit++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		index;
	long	nb;

	nb = n;
	index = lennb(n);
	str = (char *)malloc(sizeof(char) * (index + 1));
	if (str == NULL)
		return (NULL);
	str[index] = '\0';
	index--;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[index] = nb % 10 + '0';
		nb = nb / 10;
		index--;
	}
	return (str);
}
