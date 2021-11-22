#include <stdlib.h>
#include "libft.h"
/*on va chercher le bout de la liste en récursive puis on del(content), free l'élément et son pointeur*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!*lst || !del)
		return ;
	if (*lst->next)
		ft_lstclear(&lst->next, &del);
	del(*lst->content);
	free(*lst);
	free(lst);
}
