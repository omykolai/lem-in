/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:19:52 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/06 15:45:44 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_is_white_space(char c)
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

static int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	ft_parse_nbr(const char *str, int i, int sign)
{
	long long	res;

	res = 0;
	while (ft_is_digit(str[i]))
	{
		res *= 10;
		if (res >= 922337203685477580 || (res == 922337203685477580
			&& str[i] > '6'))
			return (-1);
		if (res <= -922337203685477580 || (res == -922337203685477580
			&& str[i] > '7'))
			return (0);
		if (sign)
			res -= str[i] - '0';
		else
			res += str[i] - '0';
		++i;
	}
	return ((int)res);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		cond;

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
