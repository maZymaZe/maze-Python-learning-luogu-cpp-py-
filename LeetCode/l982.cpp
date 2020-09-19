class Solution {
   public:
    int countTriplets(vector<int>& A) {
        int cnt[(1<<16)]={0};
        int ans = 0,l=A.size();
        for(int i=0; i < l; i++){
            for (int j = 0; j < (1 << 16); j++) {
                if (!(A[i] & j))
                    cnt[j]++;
            }
        }
        for(int i=0; i < l; i++){
            for (int j = 0; j < l; j++) {
                ans += cnt[A[i] & A[j]];
            }
        }
        return ans;
    }
};