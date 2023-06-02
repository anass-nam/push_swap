#include "push_swap.h"

t_list	*get_mid(t_list *list)
{
	t_list	*slow;
	t_list	*fast;

	slow = list;
	fast = list;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return (list);
}

t_list	*merge_sorted_list(t_list *a, t_list *b)
{
	t_list	*merged;
	void	*tmp;

	merged = NULL;
	while (a || b)
	{
		if (!b || (a && *(int *)(a->content) < *(int *)(b->content)))
		{
			tmp = a->content;
			a = a->next;
		}
		else
		{
			tmp = b->content;
			b = b->next;
		}
		ft_lstadd_back(&merged, ft_lstnew(tmp));
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