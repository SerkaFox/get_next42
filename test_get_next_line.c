/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssvitkin <ssvitkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:12:54 by ssvitkin          #+#    #+#             */
/*   Updated: 2024/08/08 19:12:57 by ssvitkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void test_get_next_line(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return;
    }

    char *line;
    int line_number = 1;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: %s", line_number++, line);
        free(line);
    }

    close(fd);
}

int main() {
    printf("Testing file with multiple lines:\n");
    test_get_next_line("test_files/multi_line.txt");

    printf("\nTesting empty file:\n");
    test_get_next_line("test_files/empty.txt");

    printf("\nTesting file with a single long line:\n");
    test_get_next_line("test_files/long_line.txt");

    printf("\nTesting file with no newline at end:\n");
    test_get_next_line("test_files/no_newline_end.txt");

    return 0;
}
