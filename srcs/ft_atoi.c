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

int		ft_atoi(const char *str)
{
	int		num;
	int		dec;
	int		len;

	num = 0;
	len = 0;
	dec = 1;
	while (str[len] <= 32)
		len++;
	if (str[len] == '+' || str[len] == '-')
	{
		if (str[len] == '-')
			dec = -1;
		len++;
	}
	while (str[len] && (str[len] >= '0' && str[len] <= '9'))
	{
		num = num * 10 + (str[len++] - '0');
	}
	return (num * dec);
}
