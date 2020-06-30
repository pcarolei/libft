/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 04:48:25 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:02:48 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_str_rev(char *str)
{
	char	*str_rev;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(str);
	if (str_len == 1)
		return (str);
	if (!(str_rev = (char *)malloc(str_len + 1)))
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str_rev[i] = str[str_len - 1 - i];
		i++;
	}
	str_rev[i] = '\0';
	free(str);
	return (str_rev);
}
