#include<cstdio>
#include<cstring>
const int NMAX=1e5+10;
int v[505],l1[NMAX],r1[NMAX],ans,n,m;
char a[NMAX],b[NMAX];
int cmp1(int x,int y,int l,int r){
    int len=y-x+1;
    for(int i=0;i<len;i++){
        if(a[x+i]!=b[l+i])return 0;
    }
    return l;
}
int cmp2(int x,int y,int r,int l){
    int len=y-x+1;
    for(int i=0;i<len;i++){
        if(a[x+i]!=b[r-i])return 0;
    }
    return r;
}
int ok(int x,int y){
    int len=y-x+1;
    for(int i=1;i<=m-len+1;i++){
        if(cmp1(x,y,i,i+len-1))return 1;
        if(cmp2(x,y,i+len-1,i))return 1;
    }
    return 0;
}
int main(){
    scanf("%s%s",b+1,a+1);
    n=strlen(a+1),m=strlen(b+1);
    int l,r,mid;
    for(int i=1;i<=m;i++)v[b[i]]++;
    int i=1;
    while(i<=n){
        l=i,r=n;
        if(!v[a[i]]){
            printf("-1\n");
            return 0;
        }
        while(l<r){
            mid=(l+r+1)/2;
            if(ok(i,mid))l=mid;
            else r=mid-1;
        }
        ans++;
        l1[i]=l;
        i=l+1;
    }
    printf("%d\n",ans);
    i=1;
    while(i<=n){
        r=l1[i];
        int len=r-i+1;
        for(int j=1;j<=m;j++){
            if(cmp1(i,r,j,j+len-1)){
                printf("%d %d\n",j,j+len-1);
                break;
            }
            if(cmp2(i,r,j+len-1,j)){
                printf("%d %d\n",j+len-1,j);
                break;
            }
        }
        i=r+1;
    }
    return 0;
}