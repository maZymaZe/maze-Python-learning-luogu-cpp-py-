#include<cstdio>
#include<cstring>
int a[2050],b[2050],c[2050],base,ati[300],l1,l2,l=10;
char t1[2050],t2[2050];
int main(){
    scanf("%d",&base);
    scanf("%s%s",t1,t2);
    for(int i='A';i<='Z';i++)ati[i]=l,l++;
    l1=strlen(t1);l2=strlen(t2);
    l=(l1>l2)?l1:l2;
    for(int i=l1-1;i>=0;i--){
        if(t1[i]>='A'&&t1[i]<='Z')a[l1-i]=ati[t1[i]];
        else a[l1-i]=t1[i]-'0';
    }    
    for(int i=l2-1;i>=0;i--){
        if(t2[i]>='A'&&t2[i]<='Z')b[l2-i]=ati[t2[i]];
        else b[l2-i]=t2[i]-'0';
    }
    for(int i=1;i<=l;i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/base;
        c[i]%=base;
    }
    for(int i=l+1;i>=1;i--){
        if(i==l+1&&c[i]==0)continue;
        else{
            if(c[i]>=10)printf("%c",c[i]-10+'A');
            else printf("%d",c[i]);
        }
    }    
    return 0;
}