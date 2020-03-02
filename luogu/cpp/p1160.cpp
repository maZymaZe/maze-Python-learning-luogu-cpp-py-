#include<cstdio>
struct pp{
    int z,y;
}p[100004];

int main(){
    int n,m,t1,t2,t3,r,zz,yy;
    scanf("%d",&n);
    p[1].y=0;
    p[1].z=0;
    zz=1;yy=1;
    for(int i=2;i<=n;i++){
        scanf("%d%d",&t1,&t2);
        if(t2==0){
            if(p[t1].z){
                r=p[t1].z;
                p[r].y=i;
                p[t1].z=i;
                p[i].y=t1;
                p[i].z=r;               
            }
            else{
                p[t1].z=i;
                p[i].z=0;
                p[i].y=t1;
                zz=i;
            }
        }
        if(t2==1){
            if(p[t1].y){
                r=p[t1].y;
                p[r].z=i;
                p[t1].y=i;
                p[i].z=t1;
                p[i].y=r;               
            }
            else{
                p[t1].y=i;
                p[i].y=0;
                p[i].z=t1;
                yy=i;
            }
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&t1);
        if(p[t1].y==0){
            t2=p[t1].z;
            p[t1].z=0;
            p[t2].y=0;
            if(t2)yy=t2;
        }
        else if(p[t1].z==0){
            t2=p[t1].y;
            p[t1].y=0;
            p[t2].z=0;
            if(t2)zz=t2;
        }
        else{
            t3=p[t1].z; 
            t2=p[t1].y;
            p[t1].z=0;
            p[t1].y=0;
            p[t2].z=t3;
            p[t3].y=t2;
        }
    }
    while(zz!=0){
        if(zz!=yy){
            printf("%d ",zz);
        }
        else printf("%d\n",zz);
        zz=p[zz].y;
    }
    return 0;
}