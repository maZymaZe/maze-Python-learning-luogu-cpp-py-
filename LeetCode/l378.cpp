class Solution {
public:
    bool ck(vector<vector<int>>& matrix,int mid,int k,int n){
        int i=n-1,j=0,num=0;
        while(i>=0&&j<n){
            if(matrix[i][j]<=mid){
                num+=i+1;
                j++;
            }
            else i--;
        }
        return num>=k;
        
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r){
            int mid=l+(r-l)/2;
            if(ck(matrix,mid,k,n)){
                r=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};