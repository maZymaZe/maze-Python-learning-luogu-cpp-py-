#include<cstdio>
long long num,c[10],imp,cc,sc,w;
int main(){
    scanf("%lld",&num);
    for(int i=0;i<10; i++){
        imp=1;
        while(imp<=num){
            cc=num/(imp*10);
            c[i]+=cc*imp;
            if(cc!=0&&i==0)c[i]-=imp;
            sc=(cc*10+i)*imp;
            if(sc<=num&&sc!=0){
                w=num-sc+1;
                if(w>imp)w=imp;
                c[i]+=w;
            }
            imp*=10;
        }
        printf("%lld\n",c[i]);
    }
    return 0;
}