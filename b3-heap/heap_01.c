#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));
    *p = 42;
    printf("值: %d\n", *p);
    printf("p 存的地址: %p\n", (void*)p);
    printf("p 自己的地址: %p\n", (void*)&p);
    free(p);
    return 0;
}
