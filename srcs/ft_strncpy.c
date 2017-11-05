/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:36:38 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/26 12:36:43 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	ln;
	size_t	slng;

	ln = 0;
	slng = ft_strlen(src);
	while (src[ln] != '\0' && ln < len)
	{
		dst[ln] = src[ln];
		ln++;
	}
	while (ln < len)
	{
		dst[ln] = '\0';
		ln++;
	}
	return (dst);
}
