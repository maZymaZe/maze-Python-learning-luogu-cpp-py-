#include <cstdio>
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a < b)
        a = b;
    if (a == 1)
        printf("1/1\n");
    else if (a == 2)
        printf("5/6\n");
    else if (a == 3)
        printf("2/3\n");
    else if (a == 4)
        printf("1/2\n");
    else if (a == 5)
        printf("1/3\n");
    else if (a == 6)
        printf("1/6\n");
    return 0;
}
