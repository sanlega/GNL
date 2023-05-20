/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slegaris <slegaris@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:14:57 by slegaris          #+#    #+#             */
/*   Updated: 2023/05/20 15:15:22 by slegaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <sys/time.h>

#include "get_next_line.h"

// Main that tests the speed an cycles
int main(int argc, char **argv)
{
    int fd;
    char *line;

    // Add these declarations and initializations
    clock_t start_c, end_c;
    double cpu_time_used;
    struct timeval start_w, end_w;
    double wall_time_used;

    if (argc != 2)
    {
        printf("Usage: %s <file_name>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Record the start time
    start_c = clock();
    gettimeofday(&start_w, NULL);

	line = get_next_line(fd);
	line = get_next_line(fd);
	close(fd);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Record the end time
    end_c = clock();
    gettimeofday(&end_w, NULL);

    // Calculate and print the total cycles and elapsed time
    cpu_time_used = ((double) (end_c - start_c)) / CLOCKS_PER_SEC;
    wall_time_used = (end_w.tv_sec - start_w.tv_sec) * 1000.0;
    wall_time_used += (end_w.tv_usec - start_w.tv_usec) / 1000.0;

    printf("\nTotal cycles: %ld\n", (end_c - start_c));
    printf("CPU time used: %.3fs\n", cpu_time_used);
    printf("Wall time used: %.3fms\n", wall_time_used);

    close(fd);
	system("leaks a.out");
    return (0);
}
