/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_to_numstr2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 06:00:02 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:15:02 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*complete_fract_part(char *str)
{
	char	*newstr;
	int		len;
	int		i;

	len = ft_strlen(str);
	if (len > MIN_FRACT_PART_LEN)
		return (str);
	if (!(newstr = (char *)malloc(MIN_FRACT_PART_LEN)))
		return (NULL);
	newstr[MIN_FRACT_PART_LEN] = '\0';
	i = 0;
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	while (i < MIN_FRACT_PART_LEN)
	{
		newstr[i] = '0';
		i++;
	}
	free(str);
	return (newstr);
}

static char	*concat_parts(char *integer_part, char *fract_part, char sign)
{
	char	*numstr;
	int		i;
	int		j;

	if (!(numstr = (char *)malloc(ft_strlen(integer_part) +
									ft_strlen(fract_part) + 2)))
		return (NULL);
	i = 0;
	while (integer_part[i])
	{
		numstr[i] = integer_part[i];
		i++;
	}
	numstr[i++] = '.';
	j = -1;
	while (fract_part[++j])
		numstr[i + j] = fract_part[j];
	numstr[i + j] = '\0';
	if (sign == '1')
		numstr = ft_str_char_prepend(numstr, '-');
	free(integer_part);
	free(fract_part);
	return (numstr);
}

static char	*epf_to_numstr(t_ld_epf *epf)
{
	char	*integer_part;
	char	*fract_part;

	if ((!epf->integer_part_bin) || (!epf->fract_part_bin))
		return (NULL);
	integer_part = epf_to_integer_part(epf);
	fract_part = epf_to_fract_part(epf);
	return (concat_parts(integer_part,
							complete_fract_part(fract_part), epf->sign));
}

static void	epf_free(t_ld_epf *epf)
{
	if (epf->integer_part_bin)
		free(epf->integer_part_bin);
	if (epf->fract_part_bin)
		free(epf->fract_part_bin);
}

char		*bits_to_numstr(char *bits, int sign)
{
	t_ld_epf	epf;
	char		*numstr;

	bits_to_epf(bits, &epf);
	epf.sign = (sign == 1) ? '0' : '1';
	numstr = epf_to_numstr(&epf);
	epf_free(&epf);
	return (numstr);
}
