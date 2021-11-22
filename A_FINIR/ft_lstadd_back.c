#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	while (**alst->next)
		**alst = *alst->next;
	*alst->next = new;
}
