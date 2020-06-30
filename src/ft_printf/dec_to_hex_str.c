/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:42:11 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:00:56 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*dec_to_hex_str(unsigned long long int n, int mode)
{
	char	*hex_str;
	char	*res_str;
	int		len;
	int		temp;

	len = ft_get_hex_len(n);
	hex_str = ft_strnew(len + 1);
	hex_str[len--] = '\0';
	if (n == 0)
		hex_str[0] = '0';
	while (n > 0)
	{
		temp = n % 16;
		hex_str[len] = temp + ((temp < 10) ? 48 : 55);
		len--;
		n = n / 16;
	}
	if (mode == 1)
	{
		res_str = ft_strjoin("0x", hex_str);
		free(hex_str);
		return (res_str);
	}
	return (hex_str);
}
