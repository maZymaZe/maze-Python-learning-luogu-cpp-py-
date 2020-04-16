int l;
class Solution {
public:
    vector<int> res;
    Solution(vector<int>& nums) {
        res=nums;
       l=nums.size();
       srand(time(NULL));
    }
    
    int pick(int target) {
        int w;
        while(1){
            w=(rand())%l;
            if(res[w]==target)break;
        }
        return w;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */