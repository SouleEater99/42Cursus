#include "libft_bonus.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
/*
int main()
{
	int a[3] = {1,2,3};
	t_list	*head = ft_lstnew(&a[0]);
	t_list	*current = ft_lstnew(&a[1]);

	head->next = current;
	current = ft_lstnew(&a[2]);
	head->next->next = current;


	int *i =  head->content;
	int *i1 = head->next->content;
	int *i2 = head->next->next->content;

	printf("node->content: %d\n",*i);
	printf("node->content: %d\n",*i1);
	printf("node->content: %d\n",*i2);


}
*/

