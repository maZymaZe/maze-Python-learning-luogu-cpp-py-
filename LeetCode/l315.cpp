int m;
int lowbit(int x){
    return (-x)&x;
}
void update(vector<int>& ts,int pos){
    while(pos<m){
        ts[pos]++;
        pos+=lowbit(pos);
    }
}
int ffind(vector<int>& ts,int pos){
    int ans=0;
    while(pos){
        ans+=ts[pos];
        pos-=lowbit(pos);
    }
    return ans;
}
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int l=nums.size();
        unordered_set<int> s;
        vector<int> vec,ans(l);
        for(auto i:nums){
            if(!s.count(i)){
                vec.push_back(i);
                s.insert(i);
            }
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<l;i++){
            nums[i]=(upper_bound(vec.begin(),vec.end(),nums[i]-1)-vec.begin())+2;
            m=max(m,nums[i]);
        }
        m*=2;
        vector<int> ts(m+3);
        for(int i=l-1;i>=0;i--){
            ans[i]=ffind(ts,nums[i]-1);
            update(ts,nums[i]);
        }
        return ans;
    }
};