class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int la=A.size(),lb=B.size(),pb=0;
        vector<vector<int>> ans;
        for(int i=0;i<la;i++) {
            while(pb<lb){
                if(B[pb][0]<=A[i][1]&&B[pb][1]>=A[i][0]){
                    ans.push_back(vector<int>{max(A[i][0],B[pb][0]),min(A[i][1],B[pb][1])});
                    if(B[pb][1]>A[i][1])break;
                    else pb++;
                }
                else if(B[pb][0]>A[i][1])break;
                else if(B[pb][1]<A[i][0])pb++;
            } 
        }return ans;
    }
};