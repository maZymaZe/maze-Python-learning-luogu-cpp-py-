#include<cstdio>
int n,k,f[300005],ans=0,a,b,c;
int ff(int x) {
    if(f[x] == x)return x;
    else return f[x]=ff(f[x]);
}
void merge(int x,int y){
    f[ff(x)]=ff(y);
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=3*n;i++)f[i]=i;
    for(int i=1;i<=k;i++){
        scanf("%d%d%d",&a, &b, &c);
        if(b>n||c>n){ans++; continue;}
        if(a==1){
            if(ff(b+n)== ff(c)||ff(b+2*n)== ff(c)){ans++; continue;}
            merge(b,c),merge(b+n,c+n),merge(b+2*n,c+2*n);
        }
        else{
            if(b==c){ans++; continue;}
            if(ff(c)==ff(b)||ff(c)==ff(b+2*n)){ans++; continue;}
            merge(c,b+n),merge(c+n,b+2*n),merge(c+2*n,b);
        }
    }
    printf("%d\n",ans);
    return 0;
}