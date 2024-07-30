class Solution {
   public:
    int qpow(int a,int b,int mod){
        int ans=1;
        while(b){
            if(b%2)ans=ans*a%mod;
            b/=2;
            a=a*a%mod;
        }
        return ans;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int l=variables.size();
        for(int i=0;i<l;i++){
            if(qpow(qpow(variables[i][0],variables[i][1],10),variables[i][2],variables[i][3])==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};