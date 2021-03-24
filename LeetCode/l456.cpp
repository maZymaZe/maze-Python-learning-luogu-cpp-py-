class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int l= nums.size();
        vector<int> ap(l),pm(l);
        stack<int> pos,val;
        pm[0]=nums[0];
        for(int i=1;i<l;i++){
            pm[i]=min(pm[i-1],nums[i]);
        }
        for(int i=0;i<l;i++){
            while(!pos.empty()&&val.top()<=nums[i]){
                pos.pop(),val.pop();
            }
            if(!pos.empty())ap[i]=pos.top();
            else ap[i]=-1;
            pos.push(i),val.push(nums[i]);
        }
        for(int i=1;i<l;i++){
            if(ap[i]-1>=0&&pm[ap[i]-1]<nums[i])return true;
        }
        return false;

    }
};