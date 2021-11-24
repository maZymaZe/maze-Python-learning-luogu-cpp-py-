#include <cstdio>
int mission[302], choice[302];
int mp[302][302], n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mission[mp[i][j]] == 0) {
                mission[mp[i][j]] = i;
                choice[i] = mp[i][j];
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", choice[i]);
    return 0;
}