class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int l=A.size();int ans=A[l-1]-A[0];
        for(int i=0;i<l-1;i++) {
            int a=A[i],b=A[i+1];
            int h=max(A[l-1]-K,a+K);
            int l=min(A[0]+K,b-K);
            ans=min(ans,h-l);
        }return ans;
    }
};