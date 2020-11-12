#include<cstdio>
#include<cstring>
int h,m[500004],n,p[103],c[104],ans=0x3f3f3f3f;
int main(){
    scanf("%d%d",&n,&h);
    memset(m,0x3f, sizeof(m));
    m[0]=0;
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i],&c[i]);
    for(int i=1;i<=n;i++){
        for(int j=p[i];j<=500000;j++){
            if(m[j-p[i]]+c[i]<m[j])m[j]=m[j-p[i]]+c[i];
        }
    }
    for(int i=h;i<=500000;i++){
        if(m[i]<ans)ans=m[i];
    }
    printf("%d",ans);
    return 0;
}