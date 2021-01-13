class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int d=0,l=A.size();
        for(int i=0;i<l;i++){
            d=d*2+A[i];
            d%=5;
            if(d)ans.push_back(false);
            else ans.push_back(true);
        }
        return ans;
    }
};