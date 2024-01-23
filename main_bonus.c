/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:01:50 by slegaris          #+#    #+#             */
/*   Updated: 2024/01/23 14:06:28 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd[3];
	int		i;
	char	*line;

	fd[0] = open("1.txt", O_RDONLY);
	fd[1] = open("2.txt", O_RDONLY);
	fd[2] = open("3.txt", O_RDONLY);
	i = 0;
	while (i <= 2)
	{
		while ((line = get_next_line(fd[i])) != NULL)
		{
			printf("%s", line);
			free(line);
		}
		i++;
	}
	i = 0;
	while (i <= 2)
	{
		close(fd[i]);
		i++;
	}
	return (0);
}
