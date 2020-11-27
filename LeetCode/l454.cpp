class Solution {
public:
    unordered_map<int,int> mp;
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n=A.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mp.count(A[i]+B[j]))mp[A[i]+B[j]]++;
                else mp[A[i]+B[j]]=1;
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mp.count(-C[i]-D[j]))ans+=mp[-C[i]-D[j]];
            }
        }
        return ans;
    }
};