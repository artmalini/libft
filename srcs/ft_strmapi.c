/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:02:18 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/28 11:02:24 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			ln;
	char			*mas;

	i = 0;
	if (s == NULL)
		return (NULL);
	ln = ft_strlen(s);
	mas = ft_strnew(ln);
	if (mas == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mas[i] = f(i, mas[i]);
		i++;
	}	
	mas[i] = '\0';
	return (mas);
}
