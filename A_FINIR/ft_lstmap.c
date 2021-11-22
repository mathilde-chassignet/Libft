#include <stdlib.h>
#include "libft.h"
void	ft_lstclear1(t_list **lst, void (*del)(void*))
{
	if (!*lst || !del)
		return ;
	if (*lst->next)
		ft_lstclear1(*lst->next, &del);
	del(*lst->content);
	free(*lst);
	free(lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*start;
	t_list	*new;
	t_list	*previous;

	if (!lst || !f || !del)
		return (0);
	if (!(start = malloc(sizeof(t_list))))
		return (NULL);
	start->content = f(lst->content);
	new = start;
	while (lst)
	{
		previous = new;
		if (!(new = malloc(sizeof(t_list))))
		{
			ft_lstfree(&start, &del);
			return (NULL);
		}
		new->content = f(lst->content);
		previous->next = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (start);
}
