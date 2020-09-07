#include <cstdio>
int bucket[1000] = {0}, n, m;
int main() {
    int t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &t);
        bucket[t]++;
    }
    for (int i = 1; i <= n; i++) {
        if (bucket[i]) {
            for (int j = 0; j < bucket[i]; j++)
                printf("%d ", i);
        }
    }
    return 0;
}