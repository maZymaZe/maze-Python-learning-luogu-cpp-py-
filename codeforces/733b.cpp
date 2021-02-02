#include<cstdio>
int n,a,b,tot,lp=0,lc=0,rp=0,rc=0;
int abs(int x){return x>0 ? x : -x;}
int main(){
    scanf("%d",&n);
    for(int i=1; i <= n; i++){
        scanf("%d%d",&a,&b);
        tot+=a-b;
        if(a>b&&a-b>lc){
            lp=i,lc=a-b;
        }else if(b>a&&b-a>rc){
            rp=i,rc=b-a;
        }
    }
    if(rp==0||lp==0)printf("0\n");
    else{
        if(tot==0){
            printf("%d",rc>=lc?rp:lp);
        }else if(tot>0){
            printf("%d",tot+2*rc>=abs(tot-2*lc)?rp:lp);
        }else if(tot<0){
            printf("%d",abs(tot-2*lc)>=abs(tot+2*rc)?lp:rp);
        }
    }
    return 0;
}