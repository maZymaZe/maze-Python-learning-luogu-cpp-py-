#include<cstdio>
int dis[100006],pre,now,n,m,p;
int main(){
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&now);
        if(i>0)dis[i]=now-pre;
        pre=now;
    }
    int l=1,r=n,mid,cnt; 
    while(r-l>=1){
        mid=(l+r)/2;
        cnt=0;
        for(int i=1;i<m;i++){
            if(dis[i]>mid){
                if(dis[i]%mid==0)cnt+=dis[i]/mid-1;
                else cnt+=dis[i]/mid;
            }
        }
        if(cnt<=p)r=mid;
        else l=mid;
        if(r-l==1)break;
    }
    printf("%d",r);
    return 0;
}