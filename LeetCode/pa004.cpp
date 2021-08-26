#include <cstdio>
#include <iostream>
using namespace std;

int idStack[2000000];
double tangStack[2000000];

int main() {
    int n, s = 0;
    double h;
    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        double hh;
        scanf("%lf", &hh);
        double tang = (h - hh) / (double)(i + 1);
        while (s > 0 && tangStack[s - 1] > tang)
            s--;
        if (s == 0)
            printf("0\n");
        else
            printf("%d\n", idStack[s - 1]);
        idStack[s] = i + 1;
        tangStack[s] = tang;
        s++;
    }
    return 0;
}