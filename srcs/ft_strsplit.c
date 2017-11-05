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

static int		findln(char const *s, char c)
{
	int		i;
	int		j;
	int		ln;

	i = 0;
	j = 0;
	ln = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c && s[j + 1] != '\0')
				j++;
			ln++;
			i = j;
		}
		i++;
	}
	return (ln);
}

static char		*builder(char const *s, char *mas, char c, int startwrd)
{
	int		k;
	int		count;

	k = 0;
	count = 0;
	while (*s != '\0')
	{
		if ((*s != c && count == startwrd) || (*s != c && startwrd == 1))
		{
			while (*s != c)
				mas[k++] = *s++;
			count++;
			startwrd++;
		}
		else if (*s == c)
		{
			while (*s == c)
				s++;
			count++;
		}
		else
			s++;
	}
	mas[k] = '\0';
	return (mas);
}

static char		*findword(char const *s, char c, int startwrd)
{
	char	*mas;

	if ((mas = (char *)malloc(sizeof(mas) * ft_strlen(s))) == NULL)
		return (NULL);
	mas = builder(s, mas, c, startwrd);
	return (mas);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*word;
	int		i;
	int		len;
	int		startwrd;

	i = 0;
	startwrd = 1;
	len = findln(s, c);
	if (s == NULL)
		return (NULL);
	if ((arr = (char **)malloc(sizeof(*arr) * (len))) == NULL)
		return (NULL);
	while (i < len)
	{
		word = findword(s, c, startwrd);
		arr[i] = word;
		startwrd++;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
