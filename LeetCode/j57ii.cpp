class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        target*=2;
        for(int i=sqrt(target);i>1;i--){
            if(target%i==0){
                int t=target/i-i+1;
                if(t>0&&t%2==0){
                    t/=2;
                    vector<int> v;
                    for(int j=0;j<i;j++)v.push_back(t+j);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};