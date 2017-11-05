/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:54:41 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/26 14:54:46 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char			*mas;
	const	char	*s;
	size_t			len;
	size_t			maslen;

	mas = dst;
	s = src;
	len = size;
	while (*mas != '\0' && len-- != 0)
		mas++;
	maslen = mas - dst;
	len = size - maslen;
	if (len == 0)
		return (maslen + ft_strlen(src));
	while (*s != '\0')
	{
		if (len-- != 1)
			*mas++ = *s;
		s++;
	}
	*mas = '\0';
	return (maslen + (s - src));
}
