/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:20:25 by omykolai          #+#    #+#             */
/*   Updated: 2018/02/05 19:13:08 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	res = malloc(sizeof(char) * (size + 1));
	if (res)
		res[size] = 0;
	return (res);
}
