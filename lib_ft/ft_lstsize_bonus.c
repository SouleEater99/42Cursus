#include "libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
t_list  *ft_lstnew(void *content)
{
        t_list  *node;

        node = (t_list *)malloc(sizeof(t_list));
        if (!node)
                return (NULL);
        node->content = content;
        node->next = NULL;
        return (node);
}

int	main()
{
	int	a[]= {0,1,2,100};
	t_list	*head = ft_lstnew(&a[0]);
	t_list	*current = ft_lstnew(&a[1]);

	head->next = current;
	current = ft_lstnew(&a[2]);
	head->next->next = current;
	current = ft_lstnew(&a[3]);
	head->next->next->next = current;
	int i = ft_lstsize(head);
	printf("%d\n",i);
}
