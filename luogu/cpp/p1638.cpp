#include <cstdio>
int n, m, a[1000006], l, r, c[2003], al, ar, cs = 0;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    l = 1;
    r = 0;
    cs = 0;
    al = 1;
    ar = n;
    while (r <= n) {
        while(cs<m&&r<=n){
            r++;
            c[a[r]]++;
            if(c[a[r]]==1)cs++;
        }
        if(r>n)break;
        while (c[a[l]] > 1) {
            c[a[l]]--;
            l++;
        }
        if(r-l<ar-al){
            ar=r;
            al=l;
        }
        l++;
        c[a[l-1]]--;
        if(c[a[l-1]]==0)cs--;
    }
    printf("%d %d",al,ar);
    return 0;
}