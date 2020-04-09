#include<cstdio>
#include<cstring>
long long n,b[65],l;
char t[40];
char f(long long x){
    if(x<=l)return t[x-1];
    else{
        int j=0;
        for(j=0;j<=61;j++){
            if(b[j]*l>=x){
                if(x==b[j-1]*l+1)return f(x-1);
                return f(x-b[j-1]*l-1);
            }
        }
    }
}
int main(){
    b[0]=1;
    for(int i=1;i<=61;i++){
        b[i]=b[i-1]<<1;
    }
    scanf("%s",t);
    l=strlen(t);
    scanf("%lld",&n);
    printf("%c",f(n));
    return 0;
}