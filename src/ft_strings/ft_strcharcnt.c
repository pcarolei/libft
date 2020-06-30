/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharcnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 17:14:13 by pcarolei          #+#    #+#             */
/*   Updated: 2020/06/12 17:18:46 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strcharcnt(char *str, char c)
{
	size_t	char_cnt;
	size_t	i;

	char_cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			char_cnt++;
		i++;
	}
	return (char_cnt);
}
