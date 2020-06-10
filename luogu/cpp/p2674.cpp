#include<cmath>
#include<cstdio>
int main() {
    int n,t,ans[2],g=0;
    scanf("%d",&n);
    while(n--){
        g=0;
        scanf("%d",&t);
        if(t == 1)printf("3 4\n");
        else if(t<3)printf("poor%d\n",t);
        else{
            bool f[2]={false,false};
            int b=0,c=0,num;
            for(int i=3;i<=t;i++){
                for(int j=1;j<=1400;j++){
                    num=(j)*((i-2)*j-i+4)/2;
                    if(num>t)break;
                    if(num==t){
                        if(!f[0]){
                            ans[0]=i;
                            f[0]=true;
                        }
                        else{
                            if(!f[1]){
                                f[1]=true;
                                ans[1]=i;
                                g=1;if(g==1)break;
                            }
                        }
                    }
                   
                }
                if(g==1)break;
            }
            for(int i=0;i<2;i++){
                if(f[i])printf("%d ",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}