class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int tot=0,l=machines.size();
        for(int i:machines)tot+=i;
        if(tot%l)return -1;
        int tar=tot/l;
        tot=0;
        int ans=0;
        for(int i=1;i<=l;i++){
            tot+=machines[i-1];
            ans=max(ans,abs(tar*i-tot));
            ans=max(ans,machines[i-1]-tar);
        }
        return ans;
    }
};