#include <stdio.h>
int main() {
    int* x;
    int* y;
    {
        int a=56;
        x = &a;
    }
    {
        int b=89;
        y = &b;
    }
    printf("%p - %d\n", (void*) x,*x);
    printf("%p %d\n", (void*) y,*y);
}
