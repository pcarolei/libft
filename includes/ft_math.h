/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 07:24:53 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/15 01:02:51 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

long long int	ft_max(long long a, long long b);
long long int	ft_min(long long a, long long b);
int				ft_iterative_factorial(int nb);
int				ft_recursive_factorial(int nb);
int				ft_sqrt(int nb);
int				ft_abs(int nb);
int				ft_pow(int n, int pow);
int				ft_sign(int n);

//	Complex numbers implementation
typedef	struct	s_complex
{
	float		re;
	float		im;
}				t_complex;

t_complex	*ft_complex_init(t_complex *c, float re, float im);
t_complex	*ft_complex_conj(t_complex *c, t_complex *res);
t_complex	*ft_complex_add(t_complex *a, t_complex *b, t_complex *res);
t_complex	*ft_complex_sub(t_complex *a, t_complex *b, t_complex *res);
t_complex	*ft_complex_mul(t_complex *a, t_complex *b, t_complex *res);
t_complex	*ft_complex_div(t_complex *a, t_complex *b, t_complex *res);

#endif
