#include "../include/push_swap.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *node;

        if (lst)
        {
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
}

t_list  *ft_lstnew(int  nbr)
{
        t_list  *node;

        node = (t_list *)malloc(sizeof(t_list));
        if (!node)
                return (NULL);
        node->nbr = nbr;
        node->next = NULL;
        return (node);
}

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
        t_list  *tmp;
        t_list  *to_free;

        if (lst && del)
        {
                to_free = *lst;
                while (to_free)
                {
                        tmp = to_free->next;
                        free(to_free);
                        to_free = tmp;
                }
                *lst = NULL;
        }
}

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

t_list  *ft_lstlast(t_list *lst)
{
        if (lst)
                while (lst->next)
                        lst = lst->next;
        return (lst);
}


char    *ft_strjoin_2(char *str1, char *str2)
{
        int             i;
        int             len_1;
        char    *new;

        if (!str2)
                return (NULL);
        if (!str1)
                len_1 = 0;
        else
                len_1 = ft_strlen(str1) + 1;
        i = -1;
        new = malloc(len_1 + ft_strlen(str2) + 1);
        if (!new)
                return (NULL);
        while (str1 && str1[++i])
                new[i] = str1[i];
        if (str1)
                new[i] = ' ';
        i = -1;
        while (str2[++i])
                new[len_1 + i] = str2[i];
        new[len_1 + i] = '\0';
        if (str1)
                free(str1);
        return (new);
}