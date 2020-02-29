#include<cstdio>
#include<cstring>
int main(){
    int a,b,ans[60]={0},p=0,d,e,f=0;
    char g[30];
    for(int i=10;i<=20;i++){
        g[i]='A'+i-10;
    }
    
    while(scanf("%d%d",&a,&b)!=EOF)
    {        
        memset(ans,0,sizeof(ans));
        p=0;f=0;
        d=-b;
            if(a>0){
                e=a;
                while(e!=0){
                    p++;
                    ans[p]=e%d;
                    e/=d;
                }
                for(int i=1;i<=p;i++){
                if(i%2==0)ans[i]=-ans[i];
                }
            }
            if(a<0){
                e=-a;
                while(e!=0){
                    p++;
                    ans[p]=e%d;
                    e/=d;
                }
                for(int i=1;i<=p;i++){
                if(i%2==1)ans[i]=-ans[i];
                }
            }
            if(a!=0)
            {
                for(int i=1;i<=p;i++)
                {
                    if(ans[i]<0)ans[i]+=d,ans[i+1]+=1;
                    else if(ans[i]==d)ans[i]=0,ans[i+1]-=1;
                }
                if(ans[p+1]>0)f=1;
                else if(ans[p+1]<0)f=2,ans[p+1]+=d,ans[p+2]+=1;
                else if(ans[p]==0)f=-1;
                printf("%d=",a);
                for(int i=p+f;i>0;i--){
                    if(ans[i]>9)printf("%c",g[ans[i]]);
                    else printf("%d",ans[i]);
                }
                printf("(base %d)\n",b);
            }
            else
            {
                if(b==-7) printf("0=(base %d)\n",b);
                else printf("0=0(base %d)\n",b);
            }}
    
    return 0;
}