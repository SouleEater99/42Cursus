#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main()
{
	int	fd;

	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return 1;
	ft_putchar_fd('c', fd);
	close(fd);
}
