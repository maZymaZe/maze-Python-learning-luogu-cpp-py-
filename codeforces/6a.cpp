#include <algorithm>
#include <cstdio>
using namespace std;
int a[4];
int main() {
    for (int i = 0; i < 4; i++)
        scanf("%d", &a[i]);
    sort(a, a + 4);
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (a[i] + a[j] > a[k]) {
                    printf("TRIANGLE\n");
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            for (int k = j + 1; k < 4; k++) {
                if (a[i] + a[j] == a[k]) {
                    printf("SEGMENT\n");
                    return 0;
                }
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}