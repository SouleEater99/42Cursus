#include "libft_bonus.h"



t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	t_list	*save;

	if (!lst || !f || !del)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	save = head;
	lst = lst->next;
	while (lst)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		save->next = current;
		save = save->next;
		lst = lst->next;
	}
	return (head);
}

/*
void  *ft_put(void *content)
{

	int *a = (int*)content;
	*a = *a + 1;
	return ((void *)a);
}
void    ft_lstclear2(t_list **lst, void (*del)(void*))
{
        t_list  *tmp;
        t_list  *to_free;

        to_free = *lst;
	(void) del;
        while (to_free)
        {
                tmp = to_free->next;
                //del(to_free->content);
                free(to_free);
                to_free = tmp;
        }
        *lst = NULL;
}

int     main()
{
	int *a = malloc(sizeof(int));
	int *a2 = malloc(sizeof(int));
	int *a3 = malloc(sizeof(int));
	int *a4 = malloc(sizeof(int));
	*a = 0;
	*a2 = 1;
	*a3 = 2;
	*a4 = 100;
	t_list  *head = ft_lstnew(a);
	t_list  *current = ft_lstnew(a2);

	printf("size of head --> %ld\n",sizeof(*head));
	head->next = current;
	current = ft_lstnew(a3);
	head->next->next = current;
	current = ft_lstnew(a4);
	head->next->next->next = current;


	t_list *head2 = ft_lstmap(head, ft_put, free);
	t_list *test = head2;
	int *i;
	while(test)
	{
		i = (int *)test->content;
		printf("%d \n",*i);
		test = test->next;
	}
	// free the memomry allocation:        
	ft_lstclear(&head,free);
	ft_lstclear2(&head2,free);
}
*/

