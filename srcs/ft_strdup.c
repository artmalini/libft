/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:41:18 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/26 11:41:23 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mas;

	mas = (char *)malloc(sizeof(*mas) * (ft_strlen(s1) + 1));
	if (mas == NULL)
		return (NULL);
	ft_strcpy(mas, s1);
	return (mas);
}
