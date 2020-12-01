class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int d=arr[1]-arr[0],l=arr.size();
        
        for(int i=1;i<l;i++){
            if(arr[i]-arr[i-1]==d){
                ans.push_back({arr[i-1],arr[i]});
            }else if(arr[i]-arr[i-1]<d){
                d=arr[i]-arr[i-1];
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};