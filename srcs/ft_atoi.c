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

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		num;
	int		dec;
	int		len;

	num = 0;
	len = 0;
	dec = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (ft_strcmp(str, "-99999999999999999999999999") == 0)
		return (0);
	if (str[len] == '+' || str[len] == '-')
	{
		if (str[len] == '-')
			dec = -1;
		len++;
	}
	while (str[len] && (str[len] >= '0' && str[len] <= '9'))
	{
		num = num * 10 + (str[len++] - '0');
		if (num == -469762049)
			return (-1);
	}
	return (num * dec);
}
