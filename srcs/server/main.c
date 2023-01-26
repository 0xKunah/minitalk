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
#include <unistd.h>
#include "../../libft/includes/io.h"
#include "../../includes/server/minitalk.h"

t_list	*g_list;

char	bitshift(char c, int shift)
{
	c >>= shift;
	c++;
	c <<= shift;
	return (c);
}

void	printlst(t_list *lst)
{
	while (lst)
	{
		write(1, &lst->content, 1);
		lst = lst->next;
	}
	write(1, "\n", 1);
	g_list = NULL;
}

void	sighandler(int sigcode, siginfo_t *siginfo, void *secret)
{
	static int		shift = 7;
	static char		c = 0;
	static pid_t	client_pid;

	(void)secret;
	if (siginfo->si_pid != 0)
		client_pid = siginfo->si_pid;
	if (sigcode == SIGUSR2)
		c = bitshift(c, shift);
	shift--;
	if (shift == -1)
	{
		if (c == 0)
		{
			printlst(g_list);
			kill(client_pid, SIGUSR2);
		}
		else
			ft_lstadd_back(&g_list, ft_lstnew(c));
		shift = 7;
		c = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1)
		write(1, "Kill crashed\n", 13);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &sighandler;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, (const struct sigaction *) &sa, NULL);
	sigaction(SIGUSR2, (const struct sigaction *) &sa, NULL);
	ft_printf("\033[1;36mServer started ! PID: %d\n\033[0;00m", getpid());
	while (42)
		;
}
