class Solution {
public:
    bool ck(vector<int>& bloomDay, int m, int k,int x){
        int c=0,u=0,len=bloomDay.size();
        for(int i=0;i<len; i++){
            if(bloomDay[i]<=x)u++;
            else u=0;
            if(u==k)c++,u=0;
        }
        return c>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int len=bloomDay.size();
        if((long long)m*k>len)return -1;
        int l=1,r=1000000000,mid;
        while(l<r){
            mid=(l+r)/2;
            if(ck(bloomDay,m,k,mid))r=mid;
            else l=mid+1;
        }
        return l;
    }
};