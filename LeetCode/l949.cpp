class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int mh=-1,mm=-1,th,tm;
        for(int i=1;i<=24;i++){
            th=10*(A[0])+A[1];
            tm=10*(A[2])+A[3];
            if(th<=23&&tm<60){
                if(th>mh||(th==mh&&tm>mm))mh=th,mm=tm;
            }
            next_permutation(A.begin(),A.end());
        }
        if(mh==-1&&mm==-1)return "";
        string h,m;
        if(mh>9)h=to_string(mh);
        else h="0"+to_string(mh);
        if(mm>9)m=to_string(mm);
        else m="0"+to_string(mm);
        string a=h+":"+m;
        return a;
    }
};