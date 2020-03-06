#include<cstdio>
int max(int a,int b){
    if(a>b)return a;
    else return b;
}
struct wu{
    int w,v;
}a[400];
int main()
{   
    int m,n,f[2000]={0};
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].w,&a[i].v);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=a[i].w;j--)
        {
            if(j>=a[i].w)
            {
                f[j]=max(f[j],f[j-a[i].w]+a[i].v);
            }
        }
    }
    printf("%d",f[m]);
    return 0;
}