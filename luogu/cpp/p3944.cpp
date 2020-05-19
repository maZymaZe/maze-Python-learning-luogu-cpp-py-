#include<cstdio>
int n,t,cnt[30005]={0},ans=0,g=0,m,c1=0,c2=0,c3=0,cc=0;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        cnt[t]++;
    }
    for(int i=1;i<=30000;i+=3){
        g+=cnt[i];ans+=cnt[i];c1+=cnt[i];
        g+=2*cnt[i+1],ans+=cnt[i+1];c2+=cnt[i+1];
        g+=3*cnt[i+2],ans+=cnt[i+2]*4;c3+=cnt[i+2];
        if(i>1)ans++,cc++;
        if(g>=m)break;
    }
    if(g<m){
        printf("Human Cannot Win Dog");
        return 0;
    }
    while(g>=m+3&&c3){ans-=4,c3--,g-=3;}
    while(g>m&&c1){ans-=1,c1--,g--;}
    while(g>m+1&&c2){ans-=1,c2--,g-=2;}
    printf("%d %d\n",cc,cc+c3*4+c1+c2);
    return 0;
}