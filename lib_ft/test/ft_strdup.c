#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = (char *)malloc(i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int main() {
    const char *original = "Hello, World!";
    char *duplicate = ft_strdup(original);

    if (duplicate == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;  // Exit with an error code
    }

    printf("Original string: %s\n", original);
    printf("Duplicated string: %s\n", duplicate);

    // Don't forget to free the memory when done
    free(duplicate);

    return 0;  // Exit with success
}
