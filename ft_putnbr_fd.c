#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	lg;
	
	lg = n;
	if (lg < 0)
	{
		lg = -lg;
		write(fd, "-", 1);
	}
	if (lg > 9)
	{
		ft_putnbr_fd(lg / 10, fd);
		ft_putnbr_fd(lg % 10, fd);
	}
	else
	{
		lg += '0';
		write(fd, &lg, 1);
	}
}
