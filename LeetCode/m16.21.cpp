class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        long long d=0;
        for(int i:array1)d+=i;
        for(int i:array2)d-=i;
        if(d%2)return vector<int>();
        int delta=d/2;
        unordered_set<int> s;
        for(int i:array2)s.insert(i);
        for(int i:array1)if(s.count(i-delta))return vector<int>{i,i-delta};
        return vector<int>();
    }
};