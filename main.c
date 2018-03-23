/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omykolai <omykolai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 11:14:13 by omykolai          #+#    #+#             */
/*   Updated: 2018/03/22 13:28:49 by omykolai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/lem_in.h"
#include "ft_printf/includes/ft_printf.h"

static void		print_node(t_list *node)
{
	ft_printf("%s\n", node->value);
}

static t_queue	*read_farm_file(char *fname)
{
	int		fd;
	t_queue	*input;

	fd = open(fname, O_RDONLY);
	input = read_farm(fd);
	close(fd);
	return (input);
}

static void		del(void *elem, size_t size)
{
	size = 0;
	free(elem);
}

int				main(int argc, char **argv)
{
	t_queue	*input;

	if (!(g_error_color = argc != 3))
		g_farm.ant_count = ft_atoi(argv[2]);
	if (argc == 1)
		input = read_farm(0);
	else if (argc == 2 || argc == 3)
		input = read_farm_file(argv[1]);
	else
	{
		ft_printf("Usage: ./lem-in [file_name]\n");
		return (0);
	}
	if (!find_paths())
		exit_error("no path found");
	ft_lstiter(input->first, print_node);
	ft_qdestroy(input, del);
	ft_printf("\n");
	print_path();
	return (0);
}
