#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max = 100;
int count = 10;
int format = 1;

void    print(int *arr, int size, int o)
{
    int i;
	char *format;
	char *join;

	if (o)
	{
		format = "\"%d\"";
		join = ",";
	}
	else
	{
		format = "%d";
		join = " ";
	}
	
    i = 0;
    while (i < size)
    {
        printf(format, arr[i++]);
		if (i < size)
			printf(join);
    }
}

int main() {
    int i;
    int random;
    int *arr;
    int *result;
    
    arr = (int*) malloc(max * sizeof(int));
    result = (int*) malloc(count * sizeof(int));

    i = -1;
    while (++i < max)
        arr[i] = i;
    srand(time(NULL));
    i = -1;
    while (++i < count)
    {
        random = rand() % (max - i);
        result[i] = arr[random];
        arr[random] = arr[max - i - 1];
    }
    print(result, size, format);
    return 0;
}
