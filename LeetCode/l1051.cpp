class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> t=heights;
        sort(heights.begin(),heights.end());
        int l=heights.size(),c=0;
        for(int i=0;i<l;i++)if(t[i]!=heights[i])c++;
        return c;
    }
};