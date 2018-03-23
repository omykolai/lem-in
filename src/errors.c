/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:48 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_printf/includes/ft_printf.h"
#include "../includes/lem_in.h"

void	exit_error(char *message)
{
	if (g_error_color)
		ft_dprintf(2, "{fg_bred}%s\n{eoc}", message);
	else
		ft_dprintf(2, "%s\n", message);
	exit(1);
}
