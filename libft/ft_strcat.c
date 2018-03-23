/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 22:00:28 by omykolai          #+#    #+#             */
/*   Updated: 2017/09/25 22:06:54 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dst, const char *src)
{
	char *idst;

	idst = dst;
	while (*idst != '\0')
		++idst;
	while (*src != '\0')
	{
		*idst = *src;
		++idst;
		++src;
	}
	*idst = '\0';
	return (dst);
}
