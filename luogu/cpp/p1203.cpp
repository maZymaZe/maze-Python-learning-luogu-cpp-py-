#include<cstdio>
int n,ls[400]={0},c1=0,c2=0,mx=0;
int max(int a,int b){
    if(a<b)return b;
    else return a;
}
int fl(int p){
    int cnt=0,pp=p,b=0;
    if(ls[p]!=1){
        while(ls[pp]!=1){
            cnt++;
            pp--;
            if(pp==0)pp=n;
            if(pp==p)break;
        }
    }
    b=max(b,cnt);
    pp=p;
    cnt=0;
    if(ls[p]!=-1){
        while(ls[pp]!=-1){
            cnt++;
            pp--;
            if(pp==0)pp=n;
            if(pp==p)break;
        }
    }
    b=max(b,cnt);
    return b;
}
int fr(int p){
    int cnt=0,pp=p,b=0;
    if(ls[p]!=1){
        while(ls[pp]!=1){
            cnt++;
            pp++;
            if(pp==n+1)pp=1;
            if(pp==p)break;
        }
    }
    b=max(b,cnt);
    pp=p;
    cnt=0;
    if(ls[p]!=-1){
        while(ls[pp]!=-1){
            cnt++;
            pp++;
            if(pp==n+1)pp=1;
            if(pp==p)break;
        }
    }
    b=max(b,cnt);
    return b;
}
int main(){
   
    char zz[400];
    scanf("%d",&n);
    scanf("%s",zz);
    for(int i=0;i<n;i++){
        if(zz[i]=='r')ls[i+1]=1,c1++;
        if(zz[i]=='b')ls[i+1]=-1,c2++;
    }
    if(c1==0||c2==0)printf("%d",n);
    else{
        for(int i=1;i<=n;i++){
            mx=max(mx,fl(i)+fr(i%n+1));
            if(mx>=n){
                mx=n;
                break;
            }
        }
        printf("%d",mx);
    }
    
    return 0;
}