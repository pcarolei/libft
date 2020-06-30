/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 10:38:43 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 11:28:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REGEX_H
# define FT_REGEX_H

/*
 * c - matches any literal character c
 * . - matches any single character
 * ^ - matches the beginning of the input string
 * $ - matches the end of the input string
 * * - matches zero or more occurrences of the previous character
*/

BOOL	ft_match(char *regexp, char *text);

#endif
