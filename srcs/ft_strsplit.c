/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:54:00 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/28 16:54:36 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		count_words(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			len++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (len);	
}

static int		getword_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	int		len;
	char	**mas;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	if (!(mas = (char **)malloc(sizeof(*mas) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		k = 0;
		if (!(*(mas + i) = (char *)malloc(getword_len(s, c) + 1)))
			*(mas + i) = NULL;
		while (*s == c)
			s++;
		while (*s != c && *s)
			*(*(mas + i) + k++) = (char)*s++;
		*(*(mas + i) + k) = '\0';
	}
	*(mas + i) = 0;
	return (mas);
}

/*
	while (++i < len)
	{
		k = 0;
		if (!(mas[i] = (char *)malloc(getword_len(&s[j], c) + 1)))
			mas[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			mas[i][k++] = s[j++];
		mas[i][k] = '\0';
	}
	mas[i] = 0;
*/