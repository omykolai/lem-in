/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:18:07 by omykolai          #+#    #+#             */
/*   Updated: 2017/12/26 16:32:07 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	if (!s1 && !s2)
		return (0);
	while (*s1 == *s2 && *s1 && --n)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
