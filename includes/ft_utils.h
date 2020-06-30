/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 09:43:22 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/11 07:29:53 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

int				ft_get_number_len(int n);
int				ft_get_hex_len(unsigned long long int n);
void			ft_swap_vptr(void **pa, void **pb);
unsigned int	ft_hash_pjw(char *str);

#endif
