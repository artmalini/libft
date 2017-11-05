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

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		begin;
	size_t		len;
	char		*mas;

	i = 0;
	begin = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		begin++;
		i++;
	}
	len = ft_strlen(s);
	j = len - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (j - begin > 0)
		len = j - begin;
	mas = ft_strnew(len);
	if (mas == NULL)
		return (NULL);
	return (ft_strsub(s, (unsigned int)begin, j + 1));
}
