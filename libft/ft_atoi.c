/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:44:48 by mbelaman          #+#    #+#             */
/*   Updated: 2021/04/26 15:02:41 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	convert;
	int			sign;
	int			index;

	convert = 0;
	index = 0;
	sign = 1;
	while (str[index] == '\t' || str[index] == '\n' || str[index] == '\f'
		|| str[index] == '\v' || str[index] == '\r' || str[index] == ' ')
		index++;
	if (str[index] == '+' && str[index + 1] == '-')
		return (0);
	if (str[index] == '+')
		index++;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while (str[index] != '\0' && str[index] >= '0' && str[index] <= '9')
	{
		convert = (convert * 10) + (str[index] - '0');
		index++;
	}
	return (convert * sign);
}
