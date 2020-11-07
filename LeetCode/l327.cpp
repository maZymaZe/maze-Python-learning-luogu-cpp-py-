class Solution {
public:
    int n;
    vector<int> tree;
    int lowbit(int x){ return x & (-x);}
    void update(int pos,int d){
        while(pos<=n){
            tree[pos]+=d;
            pos+=lowbit(pos);
        }
    }
    int query(int x){
        int tot=0;
        while(x){
            tot+=tree[x];
            x-=lowbit(x);
        }
        return tot;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum=0;
        vector<long long> presum={0};
        int l=nums.size();
        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
            presum.push_back(sum);
        }
        set<long long> alnums;
        for(int i=0; i<=nums.size();i++){
            alnums.insert(presum[i]);
            alnums.insert(presum[i]-lower);
            alnums.insert(presum[i]-upper);
        }
        unordered_map<long long, int> value;
        int idx=0;
        for(long long x:alnums){
            value[x]=idx;
            idx++;
        }
        int ret=0;
        n=value.size();
        tree.resize(n+1);
        for(int i=0;i<=l;i++){
            int left=value[presum[i]-upper],right=value[presum[i]-lower];
            ret+=query(right+1)-query(left);
            update(value[presum[i]]+1,1);
        }
        return ret;
    }
};