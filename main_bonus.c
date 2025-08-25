#include "get_next_line_bonus.h"
#include "minunit.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main(void)
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int	fd3 = open("test3.txt", O_RDONLY);

	char *line1;
	char *line2;
	char *line3;

	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);

		if(!line1 && !line2 && !line3)
			break ;

		if (line1)
		{
			printf("fd1: %s", line1);
			free(line1);
		}
		if (line2)
		{
			printf("fd2: %s", line2);
			free(line2);
		}
		if (line3)
		{
			printf("fd3: %s", line3);
			free(line3);
		}
	}
}
