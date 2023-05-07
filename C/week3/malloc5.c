#include <stdio.h>
#include <stdlib.h>

void *my_realloc(void *ptr, size_t old_size, size_t new_size) {
    if (new_size == 0) {  // Special case: free the buffer
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {  // Special case: allocate a new buffer
        return malloc(new_size);
    }

    // Allocate new buffer
    void *new_ptr = malloc(new_size);
    if (new_ptr == NULL) {
        return NULL;
    }

    // Copy contents from old buffer to new buffer
    size_t copy_size = old_size < new_size ? old_size : new_size;
    // Use memcpy
    memcpy(new_ptr, ptr, copy_size);

    // Free old buffer
    free(ptr);

    return new_ptr;
}

int main(int argc, char **argv) {
    /* first malloc space for 5 int */
    int *array = malloc(5 * sizeof(int));
    if(!array) return -1;

    for(int i=0; i<5; i++) {
        array[i] = i*10;
        printf("before realloc, array[%d] = %d\n", i, array[i]);
    }

    /* expand the size to 10 int */
    array = my_realloc(array, 5*sizeof(int), 10*sizeof(int));
    if(!array) return -1;

    for(int i=5; i<10; i++)
        array[i] = i*10;

    for(int i=0; i<10; i++)
        printf("after realloc, array[%d] = %d\n", i, array[i]);

    free(array);
    return 0;
}