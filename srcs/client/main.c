/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:12:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/18 12:12:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include "../../libft/includes/number.h"
#include "../../libft/includes/string.h"
#include "../../libft/includes/io.h"
#include "../../includes/client/minitalk.h"

typedef struct s_info
{
	int		bit;
	char	*string;
	char	current;
	pid_t	server_pid;
}	t_info;

t_info	init_infos(int argc, char **argv)
{
	t_info	infos;

	infos.server_pid = ft_atoi(argv[1]);
	infos.string = parse_args(argc, argv);
	infos.current = *infos.string++;
	infos.bit = 7;
	return (infos);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	t_info				infos;

	if (argc <= 2)
	{
		ft_printf("\033[1;36mUsage: ./client <server_pid> <...strings>");
		exit(0);
	}
	sa = init_sa();
	infos = init_infos(argc, argv);
	while (42)
	{
		g_status = 0;
		if (infos.bit == -1)
		{
			infos.current = *infos.string++;
			infos.bit = 7;
		}
		if (kill(infos.server_pid, (infos.current >> infos.bit & 1) + 30) == -1)
			error("invalid PID given");
		infos.bit--;
		while (!g_status)
			;
	}
	return (argc - argc);
}
