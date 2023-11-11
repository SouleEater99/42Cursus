#include <stdio.h>
#include <stdlib.h>

static	size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	char	*d;

	i = 0;
	s1_len = ft_strlen(s1);
	d = (char *)malloc(s1_len + ft_strlen(s2) + 1);
	if (d == NULL)
		return (NULL);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		d[s1_len + i] = s2[i];
		i++;
	}
	d[s1_len + i] = '\0';
	return (d);
}

#include <stdio.h>
#include <string.h>

// Your ft_strjoin function here

int main() {
    const char *str1 = "Hello, ";
    const char *str2 = "world!";
    const char *str3 = "";  // Empty string
    const char *str4 = "Test";
    
    char *result;

    // Test 1: Concatenate two non-empty strings
    result = ft_strjoin(str1, str2);
    if (strcmp(result, "Hello, world!") == 0) {
        printf("Test 1 Passed: Concatenation of 'Hello, ' and 'world!'\n");
    } else {
        printf("Test 1 Failed: Expected 'Hello, world!', but got '%s'\n", result);
    }
    free(result);

    // Test 2: Concatenate a non-empty string with an empty string
    result = ft_strjoin(str2, str3);
    if (strcmp(result, "world!") == 0) {
        printf("Test 2 Passed: Concatenation of 'world!' and an empty string\n");
    } else {
        printf("Test 2 Failed: Expected 'world!', but got '%s'\n", result);
    }
    free(result);

    // Test 3: Concatenate an empty string with a non-empty string
    result = ft_strjoin(str3, str1);
    if (strcmp(result, "Hello, ") == 0) {
        printf("Test 3 Passed: Concatenation of an empty string and 'Hello, '\n");
    } else {
        printf("Test 3 Failed: Expected 'Hello, ', but got '%s'\n", result);
    }
    free(result);

    // Test 4: Concatenate two empty strings
    result = ft_strjoin(str3, str3);
    if (strcmp(result, "") == 0) {
        printf("Test 4 Passed: Concatenation of two empty strings\n");
    } else {
        printf("Test 4 Failed: Expected an empty string, but got '%s'\n", result);
    }
    free(result);

    // Test 5: Concatenate with a non-empty string and an empty string
    result = ft_strjoin(str1, str3);
    if (strcmp(result, "Hello, ") == 0) {
        printf("Test 5 Passed: Concatenation of 'Hello, ' and an empty string\n");
    } else {
        printf("Test 5 Failed: Expected 'Hello, ', but got '%s'\n", result);
    }
    free(result);

    // Test 6: Concatenate a non-empty string with itself
    result = ft_strjoin(str4, str4);
    if (strcmp(result, "TestTest") == 0) {
        printf("Test 6 Passed: Concatenation of 'Test' and 'Test'\n");
    } else {
        printf("Test 6 Failed: Expected 'TestTest', but got '%s'\n", result);
    }
    free(result);

    return 0;
}

