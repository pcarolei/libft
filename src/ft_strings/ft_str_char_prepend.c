/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char_prepend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 05:06:26 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:02:45 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_str_char_prepend(char *res, char c)
{
	char	*new_res;
	size_t	len;
	int		i;

	len = (res == NULL) ? 0 : ft_strlen(res);
	if (!(new_res = (char *)malloc(len + 2)))
		return (NULL);
	i = 0;
	while (i < (int)len)
	{
		new_res[i] = res[i];
		i++;
	}
	new_res[i] = c;
	new_res[i + 1] = '\0';
	if (res)
		free(res);
	return (new_res);
}
