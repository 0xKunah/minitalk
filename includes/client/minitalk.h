/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:12:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/18 12:12:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>

int	g_status;

char				*parse_args(int argc, char **argv);
void				sighandler(int sigcode, siginfo_t *siginfo, void *secret);
void				end(pid_t server_pid);
void				error(char *str);
struct sigaction	init_sa(void);

#endif