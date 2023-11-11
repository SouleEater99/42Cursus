#include "libft_bonus.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		f(ptr->content);
		ptr = ptr->next;
	}
}


// int main to test your function.

/*

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
        if (!lst || !del)
                return ;
        del(lst->content);
        free(lst);
}
 
 void    ft_lstclear(t_list **lst, void (*del)(void*))
{
        t_list  *tmp;
        t_list  *to_free;

        to_free = *lst;
        while (to_free)
        {
                tmp = to_free->next;
                del(to_free->content);
                free(to_free);
                to_free = tmp;
        }
        //*lst = NULL;
}

 
 
void del(void *data) {
        if (data) {
                free(data);
        }
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



//      ft_lstdelone(head->next->next, del);
        t_list *test = head;
        int *i;
        while(test)
        {
                i = (int *)test->content;
                printf("%d \n",*i);
                test = test->next;
        }
        // free the memomry allocation:
        ft_lstiter(head, del);
        ft_lstclear(&head,del);
      

}
