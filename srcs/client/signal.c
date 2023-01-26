/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:12:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/26 17:12:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/client/minitalk.h"
#include "../../libft/includes/io.h"

void	sighandler(int sigcode, siginfo_t *siginfo, void *secret)
{
	(void)siginfo;
	(void)secret;
	if (sigcode == SIGUSR1)
		g_status = 1;
	else if (sigcode == SIGUSR2)
	{
		ft_printf("\033[1;36mMessage has been received by server !\n\033[0;00m");
		exit(0);
	}
}

void	end(pid_t server_pid)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		g_status = 0;
		kill(server_pid, SIGUSR1);
		while (!g_status)
			;
	}
	exit(0);
}

struct sigaction	init_sa(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sighandler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, (const struct sigaction *) &sa, NULL);
	sigaction(SIGUSR2, (const struct sigaction *) &sa, NULL);
	return (sa);
}
