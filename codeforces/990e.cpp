#include<cstdio>
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
const int NMAX=1e6+10;
int n,m,a[NMAX],mp[NMAX],t,k,f[NMAX],ma=0;
int main() {
    n=Read(),m=Read(),k=Read();
    for(int i=1;i<=m;i++){
        t=Read();
        mp[t]=-1;
    }
    for(int i=1;i<=k;i++)a[i]=Read();
    if(mp[0]==-1){
        printf("-1");return 0;
    }
    for(int i=0;i<n;i++){
        if(mp[i]==-1){
            f[i]=f[i-1];
            if(i-f[i]>ma)ma=i-f[i];
        }else f[i]=i;
    }
    long long ans=0x3f3f3f3f3f3f3f3f,tot=0;
    for(int i=ma+1;i<=k;i++){
        int p=0;tot=0;
        while(p<n){
            p=f[p]+i;
            tot++;
        }
        if(tot*a[i]<ans)ans=tot*a[i];
    }
    if(ans==0x3f3f3f3f3f3f3f3f){
        printf("-1");
    }else{
        printf("%lld",ans);
    }
    return 0;
}