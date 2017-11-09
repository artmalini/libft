/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:19:52 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/28 12:19:55 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str;
	char	*mas;

	if (!s)
		return (NULL);
	i = (size_t)start;
	str = ft_strlen(s);
	if ((i > str) || (len > str || len < i) || (i == len))
		return (NULL);
	mas = ft_strnew(len);
	if (mas == NULL)
		return (NULL);
	i = 0;
	while (i < len)
		mas[i++] = s[start++];
	mas[i] = '\0';
	return (mas);
}
