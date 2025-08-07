#include "get_next_line.h"
#include "minunit.h"
#include <stdio.h>
#include <unistd.h>

int	tests_run = 0;

static char	* test_print_text()
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
        printf("Linha %d: %s\n", line_count++, line);
        free(line);
    }
    close(fd);
	return (0);
}

static char	* test_hello_world()
{
	printf("Helloooo :3\n");
	return (0);
}

static char * all_tests()
{
	mu_run(test_hello_world);
	mu_run(test_print_text);
	return (0);
}

int	main(void)
{
	char	*result = all_tests();

	if (result != 0)
	{
		printf("%s\n", result);
	}
	else
	{
		printf("All tests aproved\n");
	}
	printf("Tests run: %d\n", tests_run);
	return (result != 0);
}
