class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n=nums.size(),m=nums[0].size();
        if(n*m!=r*c)return nums;
        vector<vector<int> > ans;
        vector<int> t;
        t.clear();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                t.push_back(nums[i][j]);
                if(t.size()==c){
                    ans.push_back(t);
                    t.clear();
                }
            }
        }
        return ans;
    }
};