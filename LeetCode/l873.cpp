class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size(),ans=0;
        unordered_map<int,int> idx,lgx;
        for(int i=0;i<n;i++)idx[arr[i]]=i;
        for(int k=0;k<n;k++){
            for(int j=0;j<k;j++){
                if(arr[k]-arr[j]<arr[j]&&idx.count(arr[k]-arr[j])){
                    int i=idx[arr[k]-arr[j]];
                    lgx[j*n+k]=lgx[i*n+j]+1;
                    ans=max(ans,lgx[j*n+k]+2);
                }
            }
           
        } 
        return ans>=3?ans:0;
    }
};