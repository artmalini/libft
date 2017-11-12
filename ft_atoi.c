/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 13:44:03 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/27 13:59:20 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		findresult(unsigned long acc, int dec)
{
	int		nbr;

	nbr = (int)acc * dec;
	if (nbr == -1717986919)
		return (-1);
	if (nbr == 1717986919)
		return (0);
	return (nbr);
}

static int		isdigit(const char *str)
{
	int		dec;

	dec = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			dec = -1;
		str++;
	}
	return (dec);
}

static char		*iswhite_nbr(const char *str)
{
	char	*mas;

	mas = (char *)str;
	while (*mas == 32 || (*mas >= 9 && *mas <= 13))
		mas++;
	if (*mas == '+' || *mas == '-')
		mas++;
	return (mas);
}

int				ft_atoi(const char *str)
{
	unsigned long	cutoff;
	unsigned long	acc;
	int				any;
	char			*mas;

	acc = 0;
	any = 1;
	mas = iswhite_nbr(str);
	cutoff = 1844674407370955161;
	while (*mas && (*mas >= '0' && *mas <= '9'))
	{
		if (acc > cutoff || acc == cutoff)
			any = -1;
		else
		{
			if ((acc = acc * 10 + (*mas - '0')) > cutoff)
				any = -1;
		}
		mas++;
	}
	if (any < 0)
		acc = 1844674407370955161;
	return (findresult(acc, isdigit(str)));
}
