class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1=version1.size(), l2=version2.size(),p1=0, p2 = 0,r1 = 0,r2 = 0;
        while(!(p1>=l1&&p2>=l2)){
            int v1=0,v2=0;
            while(r1<l1&&version1[r1]>='0' && version1[r1] <= '9'){
                r1++;
            }
            while(p1+1<r1&&version1[p1]=='0'){
                p1++;
            }
            if(p1<r1){
                v1=stoi(version1.substr(p1,r1-p1));
            }
            while(r2<l2&&version2[r2]>='0' && version2[r2] <= '9'){
                r2++;
            }
            while(p2+1<r2&&version2[p2]=='0'){
                p2++;
            }
            if(p2<r2){
                v2=stoi(version2.substr(p2,r2-p2));
            }
            if(v1>v2)return 1;
            if(v2>v1)return -1;
            p1=r1+1,p2=r2+1;
            r1=p1,r2=p2;
        }
        return 0;
    }
};