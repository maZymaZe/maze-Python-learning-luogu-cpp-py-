#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,k[10020],c,ans=1,hh[1520];
char t[1520];
int hash(char a[]){
    int l=strlen(a),b=1;
    for(int i=0;i<l;i++){
        b+=(int)(a[i])*hh[i];
        b%=1000000007;
    }
    return b;
}
int main(){
    srand(time(NULL));
    for(int i=0;i<=1510;i++){
        hh[i]=rand()%1000;
        hh[i]*=1000;
        hh[i]+=rand()%1000;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",t);
        k[i]=hash(t);
    }
    sort(k+1,k+1+n);
    c=k[1];
    for(int i=2;i<=n;i++){
        if(k[i]!=c){
            c=k[i];
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}