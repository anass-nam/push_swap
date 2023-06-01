#include "push_swap.h"

t_list	*get_mid(t_list *list)
{
	int	mid;

	mid = ft_lstsize(list) / 2;
	while (--mid)
		list = list->next;
	return (list);
}

t_list	*merge_sorted_list(t_list *a, t_list *b)
{
	t_list	*merged;
	t_list	*tmp;

	merged = NULL;
	while (a || b)
	{
		if (!b || (a && *(int *)(a->content) < *(int *)(b->content)))
		{
			tmp = a;
			a = a->next;
			tmp->next = NULL;
			ft_lstadd_back(&merged, tmp);
		}
		else
		{
			tmp = b;
			b = b->next;
			tmp->next = NULL;
			ft_lstadd_back(&merged, tmp);
		}
	}
	return (merged);
}

t_list	*merge_sort(t_list *list)
{
	t_list	*a;
	t_list	*b;
	t_list	*mid;

	if (list == NULL || list->next == NULL)
		return (list);
	mid = get_mid(list);
	a = list;
	b = mid->next;
	mid->next = NULL;
	a = merge_sort(a);
	b = merge_sort(b);

	return (merge_sorted_list(a, b));
}