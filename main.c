#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "libft.h"

// Fonctions de la libc
int	ft_isalpha(int arg);
int	ft_isdigit(int arg);
int	ft_isalnum(int arg);
int	ft_isascii(int arg);
int	ft_isprint(int arg);
	//void	*ft_memset(void *ptr, int value, int count); --> à finir
int	ft_tolower(int c);
int	ft_toupper(int c);
char	*ft_strchr(char *str, int c);
char	*ft_strrchr(char *str, int c);
char	*ft_strnstr(char *str, char *to_find, int len);

// Fonctions Supplémentaires
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
	//char	*ft_strmalenpi(char const *s, char (*f)(unsigned int, char));
	//void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

// Partie Bonus
t_list	*ft_lstnew(char *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);

//Fonctions de test
int	ft_atoi42(char *str);
void	str_triple(unsigned int i, char *c);

int	main(int argc, char **argv)
{
	/*int array [] = { 54, 85, 20, 63, 21 };
	int size = sizeof( int ) * 5;
	int length;
	printf("%d\n", size);
	for( length=0; length<5; length++) {
		printf( "%d ", array[ length ] );
	}
	printf( "\n" );

	ft_memset( array, 0, 5);

	for( length=0; length<5; length++) {
		printf( "%d ", array[ length ] );
	}
	printf( "\n" );*/
	
	char	**split;
	int		s;
	t_list	*lst_start_front;
	//t_list	*lst_start_back;
	t_list	*lst_new;

	lst_start_front = ft_lstnew(argv[0]);
	//lst_start_back = ft_lstnew(argv[0]);
	if (argc == 1)
		return (0);
	int	i = 1;
	while (argv[i])
	{
		// Fonctions de la libc
		printf("****** %c ******\n", argv[i][0]);
		printf("isalpha = %d : %d\n", ft_isalpha(argv[i][0]), isalpha(argv[i][0]));
		printf("isdigit = %d : %d\n", ft_isdigit(argv[i][0]), isdigit(argv[i][0]));
		printf("isalnum = %d : %d\n", ft_isalnum(argv[i][0]), isalnum(argv[i][0]));
		printf("isascii = %d : %d\n", ft_isascii(argv[i][0]), isascii(argv[i][0]));
		printf("isprint = %d : %d\n", ft_isprint(argv[i][0]), isprint(argv[i][0]));
		printf("tolower = %c : %c\n", ft_tolower(argv[i][0]), tolower(argv[i][0]));
		printf("toupper = %c : %c\n", ft_toupper(argv[i][0]), toupper(argv[i][0]));
		// Fonctions supplémentaires
		printf("itoa = %s\n", ft_itoa(ft_atoi42(argv[i])));
		ft_putnbr_fd(ft_atoi42(argv[i]), 1);
		printf(" = putnbr_fd\n ");
		//Partie Bonus
		lst_new = ft_lstnew(argv[i]);
		ft_lstadd_front(&lst_start_front, lst_new);
		lst_start_front = lst_new;
		//ft_lstadd_back(&lst_start_back, lst_new);
		printf("\n");
		i++;
	}
	if (argc >= 3)
	{
		// Fonctions de la libc
		printf("strchr = %s : %s\n", ft_strchr(argv[1], argv[2][0]), strchr(argv[1], argv[2][0]));
		printf("strrchr = %s : %s\n", ft_strrchr(argv[1], argv[2][0]), strrchr(argv[1], argv[2][0]));
		printf("strnstr = %s\n", ft_strnstr(argv[1],argv[2], 3));
		// Fonctions supplémentaires
		printf("substr = %s	(modifier start et len dans main)\n", ft_substr(argv[1], 0, 1));
		printf("strjoin = %s\n", ft_strjoin(argv[1], argv[2]));
		printf("strtrim = %s\n", ft_strtrim(argv[1], argv[2]));
		printf("split :\n");
		split = ft_split(argv[1], argv[2][0]);
		s = 0;
		while (split[s])
		{
			printf("	%s\n", split[s]);
			s++;
		}
	}
	// List Display
	printf("\n****** List Display ******\n");
	printf("lstsize = %d\n", ft_lstsize(lst_start_front));
	printf("lstlast = %s\n", ft_lstlast(lst_start_front)->content);
	printf("** Début Liste Front **\n%s\n", lst_start_front->content);
	while (lst_start_front->next)
	{
		lst_start_front = lst_start_front->next;
		printf("%s\n", lst_start_front->content);
	}
	/*printf("** Début List Back **\n%s\n", lst_start_back->content);
	while (lst_start_back->next)
	{
		lst_start_front = lst_start_front->next;
		printf("%s\n", lst_start_front->content);
	}*/
	return 0;
}


int	ft_atoi42(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + sign * (str[i] - 48);
		i++;
	}
	return (nb);
}
