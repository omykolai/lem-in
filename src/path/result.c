/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:30:41 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:40 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/path.h"

static int	set_steps(t_result *res, int *sum)
{
	t_list	*paths;
	int		len;

	paths = res->paths;
	len = 0;
	*sum = 0;
	while (paths)
	{
		*sum += ((t_path*)paths->value)->rooms->count - 1;
		++len;
		paths = paths->next;
	}
	res->steps = ft_divceil(*sum + g_farm.ant_count, len) - 1;
	return (len);
}

static void	result_check(t_result *res)
{
	int		i;
	int		sum;

	i = set_steps(res, &sum) - 1;
	if (g_farm.result.steps > res->steps)
	{
		ft_lstdel(&g_farm.result.paths, NULL);
		g_farm.result.paths = ft_lstdup(res->paths);
		g_farm.result.steps = res->steps;
	}
	if (!g_sums[i] ||
		ft_divceil(g_sums[i] + g_farm.ant_count, i + 1) - 1 > res->steps)
		g_sums[i] = sum;
}

void		result_add(t_path *path)
{
	ft_lstadd_(&g_curres.paths, path);
	result_check(&g_curres);
}
