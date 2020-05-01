class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        int m=0,l=A.size(),u,ns=0;
        for(int i=0;i<l;i++)m=max(m,A[i]),ns|=A[i];
    
    unordered_set<int> s;
    s.insert(ns);
    if( m == 0 )return 1;

    for(int i=0;i<l;i++){
       int  val=A[i];
       s.insert(val);
       for(int j=i+1;j<l;j++){
           val|=A[j];
           if(val==ns)break;
           s.insert(val);
       }
    }
    return s.size();
    }
};