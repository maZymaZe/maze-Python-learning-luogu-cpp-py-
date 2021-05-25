class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int> f(1<<10,0x3f3f3f3f);
        f[0]=0;
        for(int i=0;i<k; i++){
            unordered_map<int,int> cnt;
            int sz=0;
            for(int j=i;j<n;j+=k){
                ++cnt[nums[j]];
                ++sz;
            }
            int t2min=*min_element(f.begin(),f.end());
            vector<int> g(1<<10,t2min);
            for(int mask=0;mask<(1<<10);++mask){
                for(auto[x,cx]:cnt){
                    g[mask]=min(g[mask],f[mask^x]-cx);
                }
            }
            for_each(g.begin(), g.end(),[&](int&val){val+=sz;});
            f=move(g);
        }
        return f[0];
    }
};