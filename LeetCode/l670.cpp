
class Solution {
public:
    int maximumSwap(int num) {
        if(num<=11)return num;
        int a[10]={0},p=0,t=num,ma=0,p1=0,p2=0,ret=0,t1=0,t2=0;
        while(t){
            a[++p]=t%10;
            t/=10;
        }
        bool flag=0;
        for(int i=2;i<=p;i++){
            if(a[i-1]>a[i]){
                flag=1;
                break;
            }
        }
        if(!flag)return num;
        for(int i=1;i<=p;i++){
            if(a[i]>ma)t1=i,ma=a[i],t2=-1;
            if(a[i]<ma)p1=t1,p2=i;
        }
        swap(a[p1],a[p2]);
        for(int i=p;i>0;i--){
            ret=ret*10+a[i];
        }
        return ret;
    }
};