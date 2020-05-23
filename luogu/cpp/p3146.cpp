#include<cstdio>
int a[250],n,s[250],tp,ans=0;
int main(){
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        tp=1;
        s[1]=a[i];
        for(int j=i-1;j>0;j--){
            if(a[j]>s[tp])break;
            s[++tp]=a[j];
            while(tp>1&&s[tp]==s[tp-1])s[--tp]++;
        }
        if(ans<s[1])ans=s[1];
    }
    printf("%d",ans);
    return 0;
}