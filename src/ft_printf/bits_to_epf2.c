/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_to_epf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 05:52:31 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:00:37 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	get_integer_part_bin(t_ld_epf *epf)
{
	int	size;
	int	i;

	if (epf->exp_dec >= 64)
		size = 64;
	else if (epf->exp_dec >= 0)
		size = epf->exp_dec + 1;
	else
		size = 0;
	if (!(epf->integer_part_bin = (char *)malloc(size + 1)))
		epf->integer_part_bin = NULL;
	i = 0;
	while (i < size)
	{
		epf->integer_part_bin[i] = epf->mnt[i];
		i++;
	}
	epf->integer_part_bin[i] = '\0';
}

void	get_fract_part_bin(t_ld_epf *epf)
{
	int	integer_part_bin_size;
	int	size;
	int	i;

	integer_part_bin_size = ft_strlen(epf->integer_part_bin);
	size = 64 - integer_part_bin_size;
	if (!(epf->fract_part_bin = (char *)malloc(size + 1)))
		epf->fract_part_bin = NULL;
	i = 0;
	while (i < size)
	{
		epf->fract_part_bin[i] = epf->mnt[integer_part_bin_size + i];
		i++;
	}
	epf->fract_part_bin[i] = '\0';
}
