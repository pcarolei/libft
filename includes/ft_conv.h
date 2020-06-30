/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 09:30:45 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:31:33 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_base(long long int value, int base);
char			*ft_char_to_str(char c);
char			*ft_ctlchar_to_str(char c);

#endif
