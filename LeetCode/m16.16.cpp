class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> t=array;
        sort(t.begin(),t.end());
        int n=-1,l=t.size(),m=-1;
        for(int i=0;i<l;i++){
            if(t[i]!=array[i]){
                m=i;
                break;
            }
        }
        for(int i=l-1;i>=0;i--){
            if(t[i]!=array[i]){
                n=i;
                break;
            }
        }
        return{m,n};
    }
};