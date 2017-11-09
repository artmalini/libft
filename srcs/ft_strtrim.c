/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:07:17 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/28 15:07:27 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t		findstr(char const *s, size_t begin)
{
	size_t		j;
	size_t		last;

	if (s || begin)
	{
		j = 0;
		last = ft_strlen(s) - 1;
		while ((s[last] == ' ' || s[last] == '\n' || s[last] == '\t'))
		{
			j++;
			last--;
		}
		return (j);
	}
	return (0);
}

char				*ft_strtrim(char const *s)
{
	size_t		j;
	size_t		i;
	size_t		begin;
	char		*mas;

	if (!s)
		return (NULL);
	begin = 0;
	while (*s != '\0' && (*s == ' ' || *s == '\t' || *s == '\n') && ++begin)
		s++;
	if (ft_strlen(s) == 0)
		return (ft_strdup(""));
	j = findstr(s, begin);
	mas = ft_strnew(ft_strlen(s) - j);
	if (!mas)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - j;
	while (i < j)
		mas[i++] = *s++;
	mas[i] = '\0';
	return (mas);
}
