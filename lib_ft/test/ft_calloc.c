#include <stdio.h>
#include <stdlib.h>

void    *ft_calloc(size_t num, size_t size)
{
        void    *allocate;
        unsigned char   *bzero;
        size_t  i;

        i = 0;
        allocate = malloc(size * num);
        if (allocate == NULL)
                return (NULL);
        bzero = (unsigned char *)allocate;
        while (i < size)
                bzero[i++] = 0;
        return ((void *)allocate);
}

int main() {
    int *array;
    size_t num_elements = 5;

    // Allocate memory for an array of 5 integers
    array = (int *)ft_calloc(num_elements, sizeof(int));

    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // The allocated memory is initialized to zero
    for (size_t i = 0; i < num_elements; i++) {
        printf("array[%zu] = %d\n", i, array[i]);
    }

    // Don't forget to free the allocated memory when done
    free(array);

    return 0;
}
