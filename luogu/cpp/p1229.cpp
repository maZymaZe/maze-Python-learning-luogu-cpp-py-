#include<cstring>
#include<cstdio>
int a[1200],b[1200],len;
char aa[1300],bb[1300];
long long f(int al,int ar,int bl,int br){
    if(ar==al&&bl==br)return 1;
    else{
        long long ans=0;
        for(int i=al;i<ar;i++){
            if(i==al){
                if(a[al+1]==b[br-1])ans+= 2*f(al+1,ar,bl,br-1);
            }
            else{
                if(a[al+1]==b[bl+(i-al-1)]&&a[i+1]==b[br-1]){
                    ans+=f(al+1,i,bl,bl+(i-al-1))*f(i+1,ar,(br+i-ar),br-1);
                }
            }
    
        }
        return ans;
    }
}
int main(){
    scanf("%s%s",aa,bb);
    len=strlen(aa);
    for(int i=1;i<=len;i++){
        a[i]=aa[i-1];
        b[i]=bb[i-1];
    }
    printf("%lld",f(1,len,1,len));
    return 0;
}