#include<cstdio>
long long mx=-20000,s;
int fz,t,n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        if(fz==0){
            if(t>mx)mx=t;
            if(t>=0){
                s=t;
                fz=1;
            }
        }
        else{
            if(t+s>mx)mx=t+s;
            if(t+s<=0)fz=0;
            else s+=t;
        }      
    }
    printf("%lld",mx);
    return 0;
}