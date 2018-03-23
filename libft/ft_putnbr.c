/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:20:23 by omykolai          #+#    #+#             */
/*   Updated: 2017/09/21 19:56:20 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_rec(int n)
{
	if (n > 9 || n < -9)
	{
		putnbr_rec(n / 10);
		ft_putchar((n < 0 ? -(n % 10) : (n % 10)) + '0');
	}
	else
		ft_putchar((n < 0 ? -(n % 10) : (n % 10)) + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	putnbr_rec(n);
}
