#include "get_next_line.h"
#include "minunit.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int fd;
    char *line;
    int line_count = 1;

    // Teste 1: Arquivo normal
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Erro ao abrir test.txt");
        return (0);
    }

    printf("=== Testando arquivo normal ===\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linha %d: %s", line_count++, line);
        free(line);
    }
    close(fd);
}
