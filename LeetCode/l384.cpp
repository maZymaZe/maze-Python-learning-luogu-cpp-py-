class Solution {
public:
    vector<int> a,b;
    Solution(vector<int>& nums) {
        a=nums,b=nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        b=a;
        return b;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int l=b.size();
        for(int i=0;i<l;i++){
            int t=rand()%(i+1);
            swap(b[i],b[t]);
        }
        return b;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */