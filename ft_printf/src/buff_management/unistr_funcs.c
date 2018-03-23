/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unistr_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:44:58 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/04 21:59:39 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/ft_header.h"

size_t	u_strlen(void *str, int is_wchar, int by_wchar)
{
	return (is_wchar ? ft_wstrlen(str, by_wchar) : ft_strlen(str));
}

void	*u_strncpy(void *dst, const wchar_t *src, size_t len, int is_wchar)
{
	wchar_t *wdst;
	char	*cdst;

	wdst = (wchar_t*)dst;
	cdst = (char*)dst;
	while (len-- && *src != '\0')
	{
		if (is_wchar)
			*wdst++ = *src++;
		else
			*cdst++ = *src++;
	}
	return (dst);
}
