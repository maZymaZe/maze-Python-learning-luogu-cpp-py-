class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int ans=0,len=citations.size(),l=0,r=len,mid;
        while (l<r){
            mid=(l+r+1)/2;
            auto it=citations.end()-lower_bound(citations.begin(), citations.end(),mid);
            if(it>=mid){
                l=mid;
            }else r=mid-1;
        }
        return r;
    }
};