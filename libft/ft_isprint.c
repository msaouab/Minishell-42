/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelaman <mbelaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 18:01:14 by mbelaman          #+#    #+#             */
/*   Updated: 2021/04/26 15:03:15 by mbelaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int p)
{
	if (p < 32 || p >= 127)
		return (0);
	return (1);
}
