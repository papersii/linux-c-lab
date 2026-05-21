#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

DynamicArray* da_create() {
    DynamicArray *da = (DynamicArray *)malloc(sizeof(DynamicArray));
    da->data = (int *)malloc(4 * sizeof(int));
    da->capacity = 4;
    da->size = 0;
    return da;
}

void da_push(DynamicArray *da, int val) {
    if (da->size == da->capacity) {
	da -> data = realloc(da -> data, 2 * (da -> capacity) * sizeof(int));
	da->capacity = da->capacity * 2;

    }
        da->data[da->size] = val;
    da->size++;
}

int da_get(DynamicArray *da, int i) {
    if (i >= da->size) {
	    return -1;
    }
    else {
	    return da->data[i];
    }
}

void da_free(DynamicArray *da) {
    free(da->data);
    free(da);
}

int main() {
    DynamicArray *da = da_create();
    for (int i = 0; i < 10; i++) {
        da_push(da, i * 10);
    }
    for (int i = 0; i < 10; i++) {
        printf("da[%d] = %d\n", i, da_get(da, i));
    }
    da_free(da);
    return 0;
}
