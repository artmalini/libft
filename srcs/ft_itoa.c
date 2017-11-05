/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:28:06 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/30 17:28:12 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_itoa_length(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*mas;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_itoa_length(n) + 1;
	mas = (char *)malloc(sizeof((*mas) * (len)));
	if (mas == NULL)
		return (NULL);
	mas[len - 1] = '\0';
	if (n < 0)
	{
		n = -n;
		mas[0] = '-';
	}
	if (n == 0)
		mas[0] = '0';
	while (n)
	{
		len--;
		mas[len - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (mas);
}
