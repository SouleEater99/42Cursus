#include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
/*
int	main()
{
	char s[] = "hello world!";
	int fd = open("test.txt", O_WRONLY | O_CREAT, 0664);

	ft_putstr_fd(s, fd);
	close(fd);

}
