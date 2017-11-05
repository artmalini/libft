/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:30:58 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/28 13:31:01 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mas;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	mas = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (mas == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		mas[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		mas[i] = s2[j++];
		i++;
	}
	mas[i] = '\0';
	return (mas);
}
