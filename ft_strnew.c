/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:50:45 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/27 18:50:49 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mas;

	mas = ft_memalloc(size + 1);
	if (!mas)
	{
		ft_memdel((void *)&mas);
		return (NULL);
	}
	return (mas);
}
