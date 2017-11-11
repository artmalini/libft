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

static int	get_length(int n)
{
	int		len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char	*mas;
	int		len;
	int		del;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_length(n);
	del = n;
	if (n < 0)
		len++;
	if ((mas = ft_strnew(len)) == NULL)
		return (NULL);
	if (n < 0)
		n = -n;
	*(mas + --len) = (n % 10) + '0';
	while (n /= 10)
		*(mas + --len) = (n % 10) + '0';
	if (del < 0)
		*(mas + 0) = '-';
	return (mas);
}
