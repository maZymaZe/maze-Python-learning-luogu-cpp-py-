class Solution {
public:
    int p[2010]={0},q[1002]={0};
    bool uniqueOccurrences(vector<int>& arr) {
        for(int &i:arr)p[i+1000]++;
        for(int i=0;i<=2000;i++)if(q[p[i]])return false;else if(p[i])q[p[i]]++;
        return true;
    }

};