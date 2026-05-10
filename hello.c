#include <stdio.h>

void set_to_zero(int **pp) {
    **pp = 0;
}

int main() {
    int x = 42;
    int *p = &x;

    printf("修改前：x = %d\n", x);
    set_to_zero(&p);
    printf("修改后：x = %d\n", x);
    return 0;
}
