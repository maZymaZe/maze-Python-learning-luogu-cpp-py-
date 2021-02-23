class Solution {
public:
    int findLucky(vector<int>& arr) {
        int c[501]={0};
        for(int i:arr)c[i]++;
        for(int i=500;i>0;i--)if(c[i]==i)return i;
        return -1;
    }
};