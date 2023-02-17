#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int *arr, int size, int o)
{
    int i;
    char *format;
    char *join;

    if (o) {
        format = "\"%d\"";
        join = ",";
    } else {
        format = "%d";
        join = " ";
    }

    i = 0;
    while (i < size) {
        printf(format, arr[i++]);
        if (i < size)
            printf(join);
    }
    printf("\n");
}

int main(int ac, char **av)
{
    int i;
    int random;
    int *arr;
    int *result;
    int max;
    int count;
    int format;

    if (ac == 3)
        format = 0;
    else if (ac == 4)
        format = atoi(av[3]);
    else
        return (1);
    max = atoi(av[1]);
    count = atoi(av[2]);
    arr = (int *) malloc(max * sizeof(int));
    result = (int *) malloc(count * sizeof(int));
    i = -1;
    while (++i < max)
        arr[i] = i - (max / 2);
    srand(time(NULL));
    i = -1;
    while (++i < count) {
        random = rand() % (max - i);
        result[i] = arr[random];
        arr[random] = arr[max - i - 1];
    }
    print(result, count, format);
    free(arr);
    free(result);
    return 0;
}

