class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt=0;
        if(k==0){
            unordered_map<int,int>s;
            for(int i:nums){
                if(s.count(i)){
                    if(s[i]==1)cnt++;
                    s[i]++;
                }else s.insert({i,1});
            }
            return cnt;
        }
        unordered_map<int,int>s;
        for(int i:nums)s.insert({i,0});
        for(int i:nums){
            if(s.count(i+k)&&s[i+k]==0){
                s[i+k]=1;
                cnt++;
            }
        }
        return cnt;
    }
};