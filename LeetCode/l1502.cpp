class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int l=arr.size();
        if(l<3)return 1;
        sort(arr.begin(),arr.end());
        int d=arr[1]-arr[0];
        for(int i=2;i<l;i++)if(arr[i]-arr[i-1]!=d)return false;
        return true;
    }
};