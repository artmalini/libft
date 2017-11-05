/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakhiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:51:19 by amakhiny          #+#    #+#             */
/*   Updated: 2017/10/31 14:51:27 by amakhiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*mas;

	mas = NULL;
	mas = (t_list *)malloc(sizeof(t_list));
	if (!mas)
		return (NULL);
	if (content == NULL)
	{
		mas->content = NULL;
		mas->content_size = 0;
	}
	else
	{
		mas->content = (void *)malloc(sizeof(content_size));
		if (mas->content == NULL)
			return (NULL);
		ft_memcpy(mas->content, content, content_size);
		mas->content_size = content_size;
	}
	mas->next = NULL;
	return (mas);
}
