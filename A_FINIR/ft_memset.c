#include <stdlib.h>
#include <stdio.h>

void	*ft_memset(void *ptr, int value, unsigned int count)
{
	int	i;

	i = 0;
	ptr = malloc(count);
	if (ptr = NULL)
	{
		printf("FAIL MALLOC\n");
		return (ptr);
	}
	while (i < count)
	{
		*ptr = value;
		*ptr++;
		i++;
	}
	return (ptr);
}

int	main()
{
	int array[] = {54, 85, 20, 63, 21};
	int size = sizeof(int) * 5;
	int len;
	for (len = 0; len < 5; len++)
		printf ("%d ", array[len]);
	printf("\n");
	ft_memset(array, 0 , 5);
	for (len = 0; len < 5; len++)
		printf ("%d ", array[len]);
	printf("\n");
	return (0);
}
