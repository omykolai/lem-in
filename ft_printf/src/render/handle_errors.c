/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:38:24 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 18:02:53 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_header.h"

void	exit_message(t_error e)
{
	if (e == ERR_FORMAT)
		ft_putstr("ft_printf: wrong format\n");
	if (e == ERR_MALLOC)
		ft_putstr("ft_printf: malloc failure\n");
	exit(EXIT_FAILURE);
}
