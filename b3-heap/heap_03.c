#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(sizeof(int));
    int *q = (int *)malloc(10 * sizeof(int));

    *p = 100;
    q[9] = 999;

    free(p);
    free(q);

    return 0;
}
