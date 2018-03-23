/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:03:05 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 15:22:12 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_sprintf(char *dst, const char *format, ...);
void	*ft_sformat(const char *format, ...);
void	ft_fflush(void);

#endif
