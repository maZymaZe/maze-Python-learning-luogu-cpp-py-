class Solution {
public:
    long long q(long long x){
        long long p=5,ans=0;
        while(p<=x){
            ans+=x/p;
            p*=5;
        }
        return ans;
    }
    int preimageSizeFZF(int k) {
        long long l1=0,r1=1e10,mid,l2=0,r2=1e10;
        while(l1<r1){
            mid=(l1+r1)/2;
            if(q(mid)>=k)r1=mid;
            else l1=mid+1;
        }
        while(l2<r2){
            mid=(l2+r2+1)/2;
            if(q(mid)>k)r2=mid-1;
            else l2=mid;
        }
        if(q(l2)!=k)l2--;
        if(q(l1)!=k)l1++;
        return max(0,l2-l1+1);
    }
};