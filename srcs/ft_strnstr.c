/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:56:27 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/26 21:56:36 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	
	i = 1;
	j = 0;
	//str = (char *)big;
	if (*little == 0 && *big != 0)
		return ((char*)big);
	while (*big && i < len)
	{
		//while (big[i] != little[j] && big[i])
		//	i++;
		while (*big != *little && *big)
			++big;
		//str = (char*)&(big[i]);
		str = (char *)little;
		while (*big == *little && *big && *little && i < len)
		{
			big++, 
			little++;
			i++;
		}
		//if (!little[j])
		if (!*little)
		{
			//return (str);
			return ((char *)big);
		}

		//else
		//{
		//	little++;
		//}	
		i++;	
	}
	return (NULL);
}

	/*size_t	i;
	size_t	j;
	char	*str;

		i = 0;
		j = 0;
		if (little[i] == 0 && big[i] != 0)
			return ((char*)s1);
		while (s1[i] && i < n)
		{
			while (s1[i] != s2[j] && s1[i])
				i++;
			str = (char*)&(s1[i]);
			while (s1[i] == s2[j] && s1[i] && s2[j] && i < n)
				i++, j++;
			if (!s2[j])
				return (str);
			else
				j = 0;
		}
	return (NULL);*/
