/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:40:39 by omykolai          #+#    #+#             */
/*   Updated: 2017/11/17 15:48:05 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	i = 0;
	if (!s || !(map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		map[i] = f(i, s[i]);
		++i;
	}
	map[i] = 0;
	return (map);
}
