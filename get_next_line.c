/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:51:16 by slegaris          #+#    #+#             */
/*   Updated: 2023/05/02 15:21:18 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// #include <stdio.h>
// #include <fcntl.h>
// #include <time.h>
// #include <sys/time.h>

size_t	ft_line_length(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(buff), free(left_str), NULL);
		if (rd_bytes == 0)
			break ;
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
// // Main that tests the speed an cycles
// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;
//
//     // Add these declarations and initializations
//     clock_t start_c, end_c;
//     double cpu_time_used;
//     struct timeval start_w, end_w;
//     double wall_time_used;
//
//     if (argc != 2)
//     {
//         printf("Usage: %s <file_name>\n", argv[0]);
//         return (1);
//     }
//
//     fd = open(argv[1], O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//
//     // Record the start time
//     start_c = clock();
//     gettimeofday(&start_w, NULL);
//
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);
//     }
//
//     // Record the end time
//     end_c = clock();
//     gettimeofday(&end_w, NULL);
//
//     // Calculate and print the total cycles and elapsed time
//     cpu_time_used = ((double) (end_c - start_c)) / CLOCKS_PER_SEC;
//     wall_time_used = (end_w.tv_sec - start_w.tv_sec) * 1000.0;
//     wall_time_used += (end_w.tv_usec - start_w.tv_usec) / 1000.0;
//
//     printf("\nTotal cycles: %ld\n", (end_c - start_c));
//     printf("CPU time used: %.3fs\n", cpu_time_used);
//     printf("Wall time used: %.3fms\n", wall_time_used);
//
//     close(fd);
//     return (0);
// }
