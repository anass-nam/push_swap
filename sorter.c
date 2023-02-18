#include "push_swap.h"

int     smallest_part(int *arr, int max)
{
    int i = 0;
    int p = 0;

    while (i < max / 2)
    {
        if (arr[i] <= max / 2)
            p++;
        i++;
    }
    if (p > max / 4)
        return 0;
    return 1;
}

static char *small(int *a, int top)
{
    if (a[top] > a[top - 1] && a[top] > a[0])
        return (RA);
    return (SA);
}

static char *big(int *a, int top, int max)
{
    int flag;

    flag = smallest_part(a, max);
    if (a[top] <= max / 2)
        return PB;
    else if (flag)
        return RA;

    return RRA;
}

char    *decide(t_stack *a, t_stack *b)
{

    
	// print_stack(a->items, a->top);
	// print_stack(b->items, b->top);
	if (a->max == 3)
		return small(a->items, a->top);
    else
        return big(a->items, a->top, a->max);
    return (char *)b;
}
