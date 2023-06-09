#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

static void	print_generated(int *arr, int count)
{
	int	i;
	int	random;

	srand(time(NULL));
	i = 0;
	while (i < count)
	{
		random = rand() % (MAX - i);
		printf("%d", arr[random]);
		if (++i < count)
			printf(" ");
		arr[random] = arr[MAX - i];
	}
	printf("\n");
}

int	main(int ac, char const **av)
{
	int	*arr;
	int	count;
	int	i;

	if (ac != 2)
		return (1);
	count = atoi(av[1]);
	arr = (int *)malloc(MAX * sizeof(int));
	if (arr == NULL)
		return (1);
	i = -1;
	while (++i < MAX)
		arr[i] = i - (MAX / 2);
	print_generated(arr, count);
	return (free(arr), 0);
}
