#include<cstdio>
#include<cmath>
int mx(int a,int b){
    if(a>b)return a;
    else return b;
}

int a[100020],st[100020][20],m,n,l,r;
int rs(int p,int q){
    int d=(1.0*log(q-p+1))/log(2);
    return mx(st[p][d],st[q-(1<<d)+1][d]);
}
inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int main(){
    
    n=read(),m=read();
    for(int i=0;i<n;i++)a[i]=read(),st[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i<=n-(1<<j);i++){
            st[i][j]=mx(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    for(int i=1;i<=m;i++){
        l=read();r=read();
        printf("%d\n",rs(l-1,r-1));
    }
    return 0;
}