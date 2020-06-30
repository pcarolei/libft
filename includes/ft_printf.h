/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 09:10:15 by pcarolei          #+#    #+#             */
/*   Updated: 2020/04/10 09:16:08 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define MIN_FRACT_PART_LEN 99

typedef union	u_ld_bytes
{
	long double	num;
	char		bytes[10];
}				t_ld_bytes;

typedef struct	s_ld_epf
{
	char	sign;
	char	exp[15];
	char	mnt[64];
	char	*integer_part_bin;
	char	*fract_part_bin;
	int		exp_dec;
}				t_ld_epf;

typedef struct	s_fwplt
{
	char	*flags;
	int		width;
	int		precision;
	char	*length;
	char	type;
}				t_fwplt;

//	TODO: move bignum to ft_math
char			*bignum_multiply_by_n(char *num, int n);
char			*mult_by_10_n_times(char *num, int n);
char			*power_of_2(int n);
char			*power_of_5(int n);
char			*bignum_sum(char *num1, char *num2);
//
void			bits_to_epf(char *bits, t_ld_epf *epf);
void			get_integer_part_bin(t_ld_epf *epf);
void			get_fract_part_bin(t_ld_epf *epf);
char			*epf_to_fract_part(t_ld_epf *epf);
char			*epf_to_integer_part(t_ld_epf *epf);
char			*bits_to_numstr(char *bits, int sign);
//	FIXME: colorize into one module of two funcs
char			*colorize(char *str);
char			*replace_eoc(char *str);
char			*replace_red(char *str);
char			*replace_green(char *str);
char			*replace_yellow(char *str);
//
char			*dec_to_hex_str(unsigned long long int n, int mode);
char			*float_round_wrapper(char *str, int precision);
char			*ft_float_to_str(long double num, int sign);
int				ft_printf(char *fmt_str, ...);
int				ft_printf_fd(int fd, char *fmt_str, ...);
size_t			handler(char *str, va_list *args, int fd);
void			fwplt_free(t_fwplt *fwplt);
void			check_flags(char *str, char *cur_mod, t_fwplt *fwplt, int *pos);
void			check_width(char *str, char *cur_mod, t_fwplt *fwplt, int *pos);
t_fwplt			*fwplt_create(char *str);
size_t			handler_c(int fd, t_fwplt *fwplt, char arg);
size_t			handler_r(int fd, t_fwplt *fwplt, char arg);
size_t			handler_s(int fd, t_fwplt *fwplt, char *arg);
size_t			handler_k(int fd, t_fwplt *fwplt, char *arg);
size_t			handler_p(int fd, t_fwplt *fwplt, void *arg);
size_t			handler_di(int fd, t_fwplt *fwplt, va_list *args);
size_t			handler_u(int fd, t_fwplt *fwplt, va_list *args);
size_t			handler_o(int fd, t_fwplt *fwplt, va_list *args);
size_t			handler_x(int fd, t_fwplt *fwplt, va_list *args, int mode);
char			*handler_flags(t_fwplt *fwplt, char *str);
char			*handler_flag_minus(char *str);
int				check_str_is_neg(char *str);
int				check_str_is_pos(char *str);
int				check_str_has_no_spaces(char *str);
int				get_first_digit_pos(char *str);
char			*handler_flag_plus(char *str, t_fwplt *fwplt);
char			*handler_flag_space(char *str);
char			select_zero_or_space(t_fwplt *fwplt, char c);
char			*handler_flag_zero(char *str, t_fwplt *fwplt);
int				check_for_zero_str(char *str);
char			*add_prefix(char *str, char type, t_fwplt *fwplt);
char			*cut_extra(char *str, t_fwplt *fwplt);
char			*handler_precision_num_wrapper(t_fwplt *fwplt, char *str);
char			*handler_precision_s(t_fwplt *fwplt, char *str);
char			*handler_width(t_fwplt *fwplt, char *str);
void			num_to_bits(long double num, char *bits);
char			*parse_date(char *str);
int				parse_year(char *str, char *year);
int				check_closing_token(char c);
t_list			*parser(char *fmt_str);


#endif
