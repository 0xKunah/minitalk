/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:39:00 by dbiguene          #+#    #+#             */
/*   Updated: 2023/01/26 16:39:00 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/includes/io.h"
#include "../../libft/includes/string.h"
#include "../../libft/includes/memory.h"
#include <stdlib.h>

void	error(char *str)
{
	ft_printf("\033[1;31mError: %s\033[0;00m\n", str);
	exit(1);
}

char	*parse_args(int argc, char **argv)
{
	char	*str;
	int		i;
	int		len;

	str = NULL;
	len = 0;
	argv += 2;
	if (argc == 3 && ft_strlen(argv[0]) == 0 && !argv[0][0])
		error("given null string");
	i = 0;
	while (argv[i])
		len += ft_strlen(argv[i++]) + 1;
	str = ft_calloc(len, 1);
	while (*argv)
	{
		ft_strlcat(str, *argv++, len);
		ft_strlcat(str, " ", len);
	}
	return (str);
}
