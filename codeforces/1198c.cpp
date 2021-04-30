#include <cstdio>
#include <cstring>
const int NMAX = 5e5 + 10;
int n, m, ans[NMAX], cnt, T,u,v;
bool book[NMAX];
inline bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
inline int Read() {
    int sum = 0, f = 1;
    char c = 0;
    while (!IsDigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (IsDigit(c)) {
        sum = (sum << 3) + (sum << 1) + c - '0';
        c = getchar();
    }
    return sum * f;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        n=Read(),m = Read();
        cnt = 0;
        for(int i=1;i<=3*n;i++)book[i]=0;
        for(int i=1;i<=m;i++){
            u=Read();v= Read();
            if(!book[u]&&!book[v])book[u] =book[v]=1,ans[++cnt]=i;
        }
        if(cnt<n){
            printf("IndSet\n");
            int nw=0;
            for(int i=1;i<=3*n;i++){
                if(!book[i]){
                    printf("%d ",i);
                    nw++;
                }
                if(nw==n)break;
            }
            printf("\n");
        }else{
            printf("Matching\n");
            for(int i=1;i<=n;i++) printf("%d ",ans[i]);
            printf("\n");
        }
    }
    return 0;
}