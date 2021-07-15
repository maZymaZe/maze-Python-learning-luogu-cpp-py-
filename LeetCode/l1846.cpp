class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int l=arr.size();
        for(int i=0; i<l;i++){
            if(i==0)arr[i]=1;
            else arr[i]=min(arr[i],arr[i-1]+1);
        }
        return arr[l-1];
    }
};