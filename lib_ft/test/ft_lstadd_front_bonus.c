#include "libft_bonus.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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

int     main()
{
        int     a[] = {0,1,2,100};
        t_list  *head = NULL;
        head = ft_lstnew(&a[0]);
        t_list  *current = ft_lstnew(&a[1]);

        head->next = current;
        current = ft_lstnew(&a[2]);
        head->next->next = current;

        t_list  *new = ft_lstnew(&a[3]);
        ft_lstadd_front(&head, new);

        int *i =  new->content;
        int *i1 = new->next->content;
        int *i2 = new->next->next->content;
        int *i3 = new->next->next->next->content;

        printf("node->content: %d\n",*i);
        printf("node->content: %d\n",*i1);
        printf("node->content: %d\n",*i2);
        printf("node->content: %d\n",*i3);
}
