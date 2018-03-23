/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:23:20 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 11:19:42 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/path.h"

static int	check_all(int max_count, int len, int sum)
{
	int	min_steps;
	int	i;

	i = len;
	while (++i < max_count)
	{
		if (g_sums[max_count - i - 1])
		{
			min_steps = g_sums[max_count - i - 1] + sum;
			min_steps = ft_divceil(min_steps + g_farm.ant_count,
				max_count + len - i) - 1;
			return (min_steps);
		}
	}
	return (ft_divceil(sum + g_farm.ant_count, len) - 1);
}

static int	get_min_steps(int max_count, int len, int sum, bool append)
{
	int	min_steps;

	if (max_count > len && g_sums[max_count - len - 1])
	{
		min_steps = g_sums[max_count - len - 1] + sum;
		min_steps = ft_divceil(min_steps + g_farm.ant_count, max_count) - 1;
	}
	else if (append)
	{
		min_steps = g_search_level * (max_count - len) + sum;
		min_steps = ft_divceil(min_steps + g_farm.ant_count, max_count) - 1;
	}
	else
		min_steps = check_all(max_count, len, sum);
	return (min_steps);
}

bool		break_comb(int path_len, int max_count, bool append)
{
	t_list	*paths;
	int		len;
	int		sum;
	int		min_steps;

	paths = g_curres.paths;
	len = 1;
	sum = path_len;
	while (paths)
	{
		sum += ((t_path*)paths->value)->rooms->count - 1;
		++len;
		paths = paths->next;
	}
	if (max_count < len)
		return (false);
	min_steps = get_min_steps(max_count, len, sum, append);
	if (min_steps > g_farm.result.steps)
		return (true);
	return (false);
}

bool		break_bfs(void)
{
	bool	res;

	g_curres = g_farm.result;
	res = break_comb(g_search_level, g_farm.max_path_count, true);
	g_curres.paths = NULL;
	return (res);
}
