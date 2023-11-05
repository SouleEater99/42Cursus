#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char	*dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	res;
	size_t	dest_len;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	res = dest_len + src_len;
	if (dest_len >= size)
		return (size + src_len);
	else
	while (i < size - dest_len - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (res);
}

size_t    strlcat(char *dst, const char *src, size_t size)
{
    char    *s;
    size_t    len_dst;
    size_t    res;
    size_t    len_src;
    size_t    i;

    s = (char *)src;
    len_dst = strlen(dst);
    len_src = strlen(s);
    res = 0;
    i = 0;
    if (size > len_dst)
        res = len_src + len_dst;
    else
        res = len_src + size;
    while (s[i] && (len_dst + 1) < size)
    {
        dst[len_dst] = s[i];
        len_dst++;
        i++;
    }
    dst[len_dst] = '\0';
    return (res);
}
int main() {
    char dest[20] = "Hello ";
    const char *src = "world! abdel ali";
    char dest2[20] = "Hello ";
    
    size_t size = sizeof(dest);
    size_t result = strlcat(dest, src, size);
    size_t result2 = ft_strlcat(dest2, src, size);

    printf("Result: %s\n", dest);
    printf("Total characters copied: %zu\n", result);
    printf("Result: %s\n", dest2);
    printf("Total characters copied: %zu\n", result2);

    return 0;
}
