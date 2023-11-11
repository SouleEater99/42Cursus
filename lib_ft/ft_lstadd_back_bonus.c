#include "libft_bonus.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
}

/*
int     ft_lstsize(t_list *lst)
{
        int     i;

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

int     main()
{
        int     a[]= {0,1,2,100,200};
        t_list  *head = ft_lstnew(&a[0]);
        t_list  *current = ft_lstnew(&a[1]);

        head->next = current;
        current = ft_lstnew(&a[2]);
        head->next->next = current;
        current = ft_lstnew(&a[3]);
        head->next->next->next = current;
	t_list	*new = ft_lstnew(&a[4]);
	ft_lstadd_back(&head, new);
        printf("%d\n",ft_lstsize(head));

}
