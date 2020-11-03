#include<cstdio>
const int NMAX=2e5+10;
long long m,d,nums[NMAX],t=0,p;
int f[NMAX],tot,cnt;
struct node{
    long long x;
    int y;
}a[NMAX];
char c[3];
int ff(int x) {
    if (f[x] == x)return x;
    return f[x]=ff(f[x]);
}
int main(){
    scanf("%lld%lld",&m,&d);
    for(int i=1;i<=m;i++){
        getchar();
        scanf("%s%lld",c,&p);
        if(c[0]=='A'){
            p=(p+t)%d;
            tot++;
            nums[tot]=p;
            f[tot]=tot;
            while(p>a[cnt].x&&cnt){
                f[a[cnt].y]=tot;
                cnt--;
            }
            a[++cnt].x=p,a[cnt].y=tot;
        }else{
            p=tot-p+1;
            int ans=ff(p);
            t=nums[ans];
            printf("%lld\n",t);
        }
    }
    return 0;
}