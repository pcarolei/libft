/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_regex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 10:40:24 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 11:58:59 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static BOOL	ft_match_here(char *regexp, char *text);
static BOOL	ft_match_star(int c, char *regexp, char *text);

/*
 * ft_match - search for regexp anywhere in text
*/

BOOL		ft_match(char *regexp, char *text)
{
	if (!regexp || !text)
		return (FALSE);
	if (regexp[0] == '^')
		return (ft_match_here(regexp + 1, text));
	if (ft_match_here(regexp, text))
		return (TRUE);
	while (*text++ != '\0')
	{
		if (ft_match_here(regexp, text))
			return (TRUE);
	}
	return (FALSE);
}

/*
 * ft_match_here - search for regexp at beginning of text
*/

static BOOL	ft_match_here(char *regexp, char *text)
{
	if (regexp[0] == '\0')
		return (TRUE);
	if (regexp[0] == '$' && (regexp[1] == '\0'))
		return (*text == '\0');
	if (regexp[1] == '*')
		return (ft_match_star(regexp[0], regexp + 2, text));
	if (*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
		return (ft_match_here(regexp + 1, text + 1));
	return (FALSE);
}

/*
 * ft_match_star - search for c*regexp at beginning of text
*/

static BOOL	ft_match_star(int c, char *regexp, char *text)
{
	if (ft_match_here(regexp, text))
		return (TRUE);
	while (*text != '\0' && (*text++ == c || c == '.'))
	{
		if (ft_match_here(regexp, text))
			return (TRUE);
	}
	return (FALSE);
}
