/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 17:25:00 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/07 13:20:26 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

static int		ft_is_white_space(char c)
{
	if (c == ' ' ||
		c == '\t' ||
		c == '\n' ||
		c == '\v' ||
		c == '\f' ||
		c == '\r')
		return (1);
	else
		return (0);
}

static int		ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static intmax_t	ft_parse_nbr(const char *str, int i, int sign)
{
	intmax_t	res;

	res = 0;
	while (ft_is_digit(str[i]))
	{
		res *= 10;
		if (sign)
			res -= str[i] - '0';
		else
			res += str[i] - '0';
		++i;
	}
	return (res);
}

intmax_t		ft_atoimax(const char *str)
{
	int			i;
	intmax_t	res;
	int			cond;

	i = 0;
	res = 0;
	cond = 0;
	while (ft_is_white_space(*str))
		++str;
	if (str[i] == '+')
	{
		if (ft_is_digit(str[i + 1]))
			res = ft_parse_nbr(str, i + 1, 0);
	}
	else
	{
		if (str[i] == '-')
			res = ft_parse_nbr(str, i + 1, 1);
		else if (ft_is_digit(str[i]))
			res = ft_parse_nbr(str, i, 0);
		else
			return (0);
	}
	return (res);
}
