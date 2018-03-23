/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:48:48 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/18 12:48:54 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_rec_fd(int n, int fd)
{
	if (n > 9 || n < -9)
	{
		putnbr_rec_fd(n / 10, fd);
		ft_putchar_fd((n < 0 ? -(n % 10) : (n % 10)) + '0', fd);
	}
	else
		ft_putchar_fd((n < 0 ? -(n % 10) : (n % 10)) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	putnbr_rec_fd(n, fd);
}
