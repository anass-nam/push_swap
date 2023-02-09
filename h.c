





int main(int ac, char const **av)
{
    int *items;

    items = parse_items(av + 1, --ac);
    while (ac--)
        printf("%d\n", items[ac]);
    return 0;
}


