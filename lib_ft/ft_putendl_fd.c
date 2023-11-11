#include <unistd.h>
#include <fcntl.h>

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}
/*
int     main()
{
        char s[] = "hello world!";
        int fd = open("test.txt", O_WRONLY | O_CREAT, 0664);

        ft_putendl_fd(s, fd);
        close(fd);

}

