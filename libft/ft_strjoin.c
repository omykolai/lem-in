/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:48:13 by omykolai          #+#    #+#             */
/*   Updated: 2017/12/26 16:33:19 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*ijoin;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	ijoin = join;
	while (*s1)
		*ijoin++ = *s1++;
	while (*s2)
		*ijoin++ = *s2++;
	*ijoin = 0;
	return (join);
}
