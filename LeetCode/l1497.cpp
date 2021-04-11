class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> f(k);
        for(int i:arr)f[((i%k)+k)%k]++;
        for(int i=1;i<=k/2;i++)if(f[i]!=f[k-i])return false;
        return f[0]%2==0;
    }
};