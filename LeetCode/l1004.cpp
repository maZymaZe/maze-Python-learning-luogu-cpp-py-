class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int len=A.size(), ans=0,l=0,r=0;
        while(r<len&&K){
            if(A[r]==0)K--;
            r++;
        }
        while(r<len&&A[r])r++;
        ans=r-l;
        while(r<len){
            while(l<len&&A[l])l++;
            l++;
            r++;
            while(r<len&&A[r])r++;
            ans=max(ans,r-l);
        }
        return ans;
    }
};