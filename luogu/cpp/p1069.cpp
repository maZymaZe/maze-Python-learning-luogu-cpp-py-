#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,mi,m1,m2,s[10005],zs[30005];
int zys[100],c[100],p=0,cnt,ans=99999999,ff=0;

void shai(){
    for(int i=2;i<=m1;i++){
        if(zs[i]==0){
            int t,cc;
            t=m1,cc=0;
            while(t%i==0){
                cc++;
                t/=i;
            }
            for(int j=2*i;j<=m1;j+=i)
            zs[j]=1;

            if(cc){p++;
            zys[p]=i;
            c[p]=cc;}
        }
    }
}
int main(){
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=n;i++)scanf("%d",&s[i]);
    if(m1==1)printf("0");
    else{
        shai();
    

       for(int i=1;i<=n;i++){
            int f=1,nt=-1;
            for(int j=1;j<=p;j++){
                if(s[i]%zys[j]!=0){
                    f=0;
                    break;
                }
                int t=s[i],cc=0;
                while(t%zys[j]==0){
                    cc++;
                    t/=zys[j];
                }
                nt=max(nt,(int)ceil(1.0*m2*c[j]/cc));
            }
            if(f==0)continue;
            else {
                ans=min(ans,nt);
                ff=1;
            }
        }
        if(ff==1)printf("%d",ans);
        else printf("-1"); 
    }
    return 0;
}