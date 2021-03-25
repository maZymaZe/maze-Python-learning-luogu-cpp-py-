class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans=0,l=citations.size(),cnt=0,p;
        p=0;
        for(int i=1;i<=l;i++)
        {
            while(p<l&&citations[p]<i){
                cnt++,p++;
            }
            if(l-cnt>=i)ans=i;
        }
        return ans;
    }
};