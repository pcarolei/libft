/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:30:29 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:03:30 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	dst_len;

	dst_len = 0;
	while (*dst && (size > 0))
	{
		size--;
		dst += sizeof(char);
		dst_len++;
	}
	if (size > 0)
	{
		ft_strncpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (dst_len + ft_strlen(src));
}
