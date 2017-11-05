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

	i = (size_t)start;
	str = ft_strlen(s);
	if ((i > str) || (len > str || len < i) || (i == len))
		return (NULL);
	str = len - i;
	mas = ft_strnew(str);
	if (mas == NULL)
		return (NULL);
	i = 0;
	while (start < len)
		mas[i++] = s[start++];
	mas[i] = '\0';
	return (mas);
}
