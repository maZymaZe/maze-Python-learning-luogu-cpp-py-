class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int len=arr.size(),p=0,pl=pieces.size();
        while(p<len){
            int f=-1;
            for(int i=0;i<pl;i++){
                if(arr[p]==pieces[i][0]){
                    f=i;break;
                }
            }
            if(f==-1)return false;
            int l=pieces[f].size();
            for(int i=0;i<l;i++){
                if(arr[p]==pieces[f][i])p++;
                else return false;
            }
        }
        return true;
    }
};