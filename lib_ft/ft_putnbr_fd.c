#include <unistd.h>
#include <fcntl.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else if (nbr <= 9)
		ft_putchar_fd(nbr + '0', fd);
}
/*
int     main()
{
        int s= 0;
        int fd = open("test1.txt", O_WRONLY | O_CREAT, 0664);

        ft_putnbr_fd(s, fd);
        close(fd);

}

