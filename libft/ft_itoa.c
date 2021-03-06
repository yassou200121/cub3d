/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-alou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:54:54 by yel-alou          #+#    #+#             */
/*   Updated: 2019/11/21 14:54:55 by yel-alou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nbrlen(int nbr, unsigned int unbr)
{
	unsigned int len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		unbr = -nbr;
	}
	if (unbr == 0)
		return (1);
	while (unbr)
	{
		unbr = unbr / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int nbr)
{
	unsigned int	unbr;
	unsigned int	len;
	char			*nbr_final;

	len = 0;
	unbr = nbr;
	len = ft_nbrlen(nbr, unbr);
	if (!(nbr_final = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (nbr < 0)
	{
		nbr_final[0] = '-';
		unbr = -nbr;
	}
	nbr_final[len] = '\0';
	len--;
	while (unbr >= 10)
	{
		nbr_final[len] = unbr % 10 + '0';
		unbr = unbr / 10;
		len--;
	}
	nbr_final[len] = unbr % 10 + '0';
	return (nbr_final);
}
