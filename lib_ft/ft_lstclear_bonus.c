#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*to_free;

	to_free = *lst;
	while (to_free)
	{
		tmp = to_free->next;
		del(to_free->content);
		free(to_free);
		to_free = tmp;
	}
	*lst = NULL;
}

