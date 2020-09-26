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
const int NMAX=1e7+1;
int n,a[NMAX],stk[NMAX],ls[NMAX],rs[NMAX];
long long L,R;
int main(){
    scanf("%d",&n);
    for(int i=1,pos=0,top=0;i<=n;i++){
        a[i]=Read();
        pos=top;
        while(pos&&a[stk[pos]]>a[i])pos--;
        if(pos)rs[stk[pos]]=i;
        if(pos<top)ls[i]=stk[pos+1];
        stk[++pos]=i;
        top=pos;
    }
    for(int i=1;i<=n;i++)L^=1LL*i*(ls[i]+1),R^=1LL*i*(rs[i]+1);
    printf("%lld %lld",L,R);
    return 0;
}