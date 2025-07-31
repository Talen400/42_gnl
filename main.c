#include "get_next_line.h"
#include "minunit.h"
#include <stdio.h>

int	tests_run = 0;

static char	* test_hello_world()
{
	printf("Helloooo :3\n");
	return (0);
}

static char * all_tests()
{
	mu_run(test_hello_world);
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
