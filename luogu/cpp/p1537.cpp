#include <cstdio>
#include <cstring>
int tot=0, a[7], v[60001], s, k = 1;
int main() {
    for (int i = 1; i <= 6; i++) {
        scanf("%d", &a[i]);
        tot += a[i] * i;
    }
    do {
        printf("Collection #%d:\n", k);
        if (tot%2== 0) {
            memset(v, 0, sizeof(v));
            v[0] = 1;
            for(int i = 1; i <= 6; i++){
                for(int t=a[i];t>0;t>>=1){
                    int f=(t>>1)+(t&1);
                    for(int j=tot;j>=f*i*2;j--){
                        if(v[j - f * i * 2])
                        v[j] = 1;
                    }
                }
            }
            if(v[tot])printf("Can be divided.\n\n");
            else printf("Can't be divided.\n\n");
        } else
            printf("Can't be divided.\n\n");
        k++;
        tot=0;
        for (int i = 1; i <= 6; i++) {
            scanf("%d", &a[i]);
            tot += a[i] * i;
        }
    } while (tot > 0);
    return 0;
}