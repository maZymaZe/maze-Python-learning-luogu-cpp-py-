class Solution {
public:
    vector<int> partitionLabels(string S) {
        int l=S.length(),sum[504][26]={0};
        for(int i=1;i<=l;i++){
            for(int j=0;j<26;j++){
                if(S[i-1]==j+'a')sum[i][j]=sum[i-1][j]+1;
                else sum[i][j]=sum[i-1][j];
            }
        }
        vector<int> result;
        int pre=0;
        for(int i=1;i<=l;i++){
            int f=1;
            for(int j=0;j<26;j++){
                if(!(sum[i][j]==0||sum[i][j]==sum[l][j])){
                    f=0;break;
                }
            }
            if(f)result.push_back(i-pre),pre=i;
        }
        return result;

    }
};