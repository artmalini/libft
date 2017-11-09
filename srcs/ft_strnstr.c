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
	char	*ret;
	
	i = 0;
	if (*little == 0 && *big != 0)
		return ((char*)big);
	while (*big != '\0' && i < len)
	{		
		while (*big != '\0' && *little != '\0' && *big != *little)
		{
			i++;
			big++;
		}
		ret = (char *)big;
		while ((*big != '\0' && *little != '\0') && (*big == *little && i < len))
		{
			i++;
			big++;
			little++;
		}
		if (*little == '\0')
		{
			return (ret);
		}
	}
	return (NULL);
}
