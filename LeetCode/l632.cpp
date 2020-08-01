struct pr{
    int g,val;
};
struct cmp{
    bool operator()(pr a,pr b){
        return a.val>b.val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int> pt(n);
        priority_queue<pr,vector<pr>,cmp> q;
        int mi=nums[0][0],ma=nums[0][0];
        for(int i=0;i<n;i++){
            if(ma<nums[i][0])ma=nums[i][0];
            if(mi>nums[i][0])mi=nums[i][0];
            q.push({i,nums[i][0]});
            pt[i]=1;
        }
        int ansl=mi,ansr=ma;
        while(1){
            pr tmp=q.top();
            q.pop();
            if(pt[tmp.g]==nums[tmp.g].size())break;
            ma=max(ma,nums[tmp.g][pt[tmp.g]]);
            q.push({tmp.g,nums[tmp.g][pt[tmp.g]]});
            pt[tmp.g]++;
            mi=q.top().val;
            if(ma-mi<ansr-ansl)ansr=ma,ansl=mi;
        }
        return vector<int>{ansl,ansr};

    }
};