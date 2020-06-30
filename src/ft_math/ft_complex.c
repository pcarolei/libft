/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 07:29:57 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 08:56:16 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_complex	*ft_complex_init(t_complex *c, float re, float im)
{
	if (!c)
		return (NULL);
	c->re = re;
	c->im = im;
	return (c);
}

t_complex	*ft_complex_conj(t_complex *c, t_complex *res)
{
	if (!c || !res)
		return (NULL);
	res->re = c->re;
	res->im = (-1) * (c->im);
	return (res);
}

t_complex	*ft_complex_add(t_complex *a, t_complex *b, t_complex *res)
{
	if (!a || !b || !res)
		return (NULL);
	res->re = a->re + b->re;
	res->im = a->im + b->im;
	return (res);
}

t_complex	*ft_complex_sub(t_complex *a, t_complex *b, t_complex *res)
{
	if (!a || !b || !res)
		return (NULL);
	res->re = a->re - b->re;
	res->im = a->im - b->im;
	return (res);
}

t_complex	*ft_complex_mul(t_complex *a, t_complex *b, t_complex *res)
{
	if (!a || !b || !res)
		return (NULL);
	res->re = a->re * b->re - a->im * b->im;
	res->im = a->im * b->re + a->re * b->im;
	return (res);
}

t_complex	*ft_complex_div(t_complex *a, t_complex *b, t_complex *res)
{
	if ((!a || !b || !res) || ((b->re == 0) && (b->im == 0)))
		return (NULL);
	res->re = (a->re * b->re + a->im * b->im) / (b->re * b->re + b->im * b->im);
	res->im = (a->im * b->re - a->re * b->im) / (b->re * b->re + b->im * b->im);
	return (res);
}
