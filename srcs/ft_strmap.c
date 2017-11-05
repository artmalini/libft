/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 22:11:58 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/27 22:12:04 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	ln;
	char	*mas;

	i = 0;
	if (s == NULL)
		return (NULL);
	ln = ft_strlen(s);
	mas = ft_strnew(ln);
	if (mas == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mas[i] = f(mas[i]);
		i++;
	}
	mas[i] = '\0';
	return (mas);
}
