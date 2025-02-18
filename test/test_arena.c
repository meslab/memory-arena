#include "../include/arena.h"
#include <stdio.h>

int main() {
    MemoryArena arena;
    arena_init(&arena, 1024 * 1024); // 1 MB arena

    // Test allocations
    int *int_array = (int *)arena_alloc(&arena, 10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        int_array[i] = i;
    }

    double *double_array = (double *)arena_alloc(&arena, 5 * sizeof(double));
    for (int i = 0; i < 5; i++) {
        double_array[i] = i * 1.0;
    }

    // Print results
    printf("Int array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n");

    printf("Double array: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", double_array[i]);
    }
    printf("\n");

    // Reset and reuse the arena
    arena_reset(&arena);
    char *str = (char *)arena_alloc(&arena, 50);
    snprintf(str, 50, "Hello, Memory Arena!");
    printf("String: %s\n", str);

    // Clean up
    arena_free(&arena);
    return 0;
}
