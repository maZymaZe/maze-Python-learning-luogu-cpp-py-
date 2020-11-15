#include<cstdio>
#include<cstring>
const int NMAX=503;
long long p,f,c,a[NMAX],tot,ans=1e16,mp[NMAX][NMAX],ret;
int main(){
    scanf("%lld%lld%lld",&p,&f,&c);
    for(int i=0;i<=p;i++){
        for(int j=0;j<=p;j++){
            if(i!=j)mp[i][j]=1e10;
            else mp[i][j]=0;
        }
    }
    int t1,t2,t3;
    for(int i=0;i<f;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<c;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        mp[t1][t2]=mp[t2][t1]=t3;
    }
    for(int k=1;k<=p;k++){
        for(int i=1;i<=p;i++){
            for(int j=1;j<=p;j++){
                if(mp[i][j]>mp[i][k]+mp[k][j])
                mp[i][j]=mp[i][k]+mp[k][j];
            }
        }
    }
    for(int i=1;i<=p;i++){
        tot=0;
        for(int j=0;j<f;j++){
            tot+=mp[i][a[j]];
        }
        if(tot<ans)ans=tot,ret=i;
    }
    printf("%lld",ret);
    return 0;
}