/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:28:16 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:00:28 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	swap_str(char **str1, char **str2, int mode)
{
	char	*swp;

	if (mode == 0)
		return ;
	swp = *str1;
	*str1 = *str2;
	*str2 = swp;
}

char		*bignum_sum(char *num1, char *num2)
{
	char	*res;
	int		sum;
	int		i;
	int		carry;

	swap_str(&num1, &num2, ft_strlen(num1) > ft_strlen(num2));
	num1 = ft_str_rev(num1);
	num2 = ft_str_rev(num2);
	i = 0;
	carry = 0;
	res = NULL;
	while (i < (int)ft_strlen(num2))
	{
		if (i < (int)ft_strlen(num1))
			sum = ((num1[i] - '0') + (num2[i] - '0') + carry);
		else
			sum = (num2[i] - '0') + carry;
		res = ft_str_char_prepend(res, (sum % 10) + '0');
		carry = sum / 10;
		i++;
	}
	if (carry)
		res = ft_str_char_prepend(res, carry + '0');
	ft_free2(num1, num2);
	return (ft_str_rev(res));
}

char	*bignum_multiply_by_n(char *num, int n)
{
	int		i;
	int		carry;
	int		prod;
	int		len;
	char	*res;

	i = 0;
	carry = 0;
	len = (int)ft_strlen(num);
	num = ft_str_rev(num);
	res = NULL;
	while (i < len)
	{
		prod = (num[i] - '0') * n + carry;
		res = ft_str_char_prepend(res, (prod % 10) + '0');
		carry = prod / 10;
		i++;
	}
	while (carry)
	{
		res = ft_str_char_prepend(res, (carry % 10) + '0');
		carry /= 10;
	}
	free(num);
	return (ft_str_rev(res));
}
