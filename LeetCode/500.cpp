class Solution {
public:
    int ct[26]={0};
    int ck(char c){
        if(c>='A'&&c<='Z')return ct[c-'A'];
        return ct[c-'a'];
    }
    vector<string> ans;
    vector<string> findWords(vector<string>& words) {
        ct[4]=ct[8]=ct[14]=ct[15]=ct[16]=ct[17]=ct[19]=ct[20]=ct[22]=ct[24]=1;
        ct[0]=ct[3]=ct[5]=ct[6]=ct[7]=ct[9]=ct[10]=ct[11]=ct[18]=2;
        ct[1]=ct[2]=ct[12]=ct[13]=ct[21]=ct[23]=ct[25]=3;
        int len=words.size();
        for(int i=0;i<len;i++){
            int pr=ck(words[i][0]),f=1,l=words[i].size();
            for(int j=1;j<l;j++){
                if(ck(words[i][j])!=pr){
                    f=0;break;
                }
            }
            if(f)ans.push_back(words[i]);
        }
        return ans;
    }
};