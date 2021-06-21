class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                int c =0,t;
                t=i;
                while(t){c+=(t&1),t>>=1;}
                t=j;
                while(t){c+=(t&1),t>>=1;}
                if(c==turnedOn){
                    string a;
                    a+=to_string(i);
                    a+=":";
                    if(j<10)a+="0";
                    a+=to_string(j);
                    ans.push_back(a);
                }
                
            }
        }
        return ans;
    }
};