class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> fre;
        for(const string& word : words){
            int mask=0;
            for(char c :word){
                mask |= (1<<(c-'a'));
            }
             if (__builtin_popcount(mask) <= 7) {
                 ++fre[mask];
             }
        }
        vector<int> ans;
        for(const string& puzzle :puzzles){
            int tot=0;
            int mask=0;
            for(int i=1;i<7;i++){
                mask |=(1<<(puzzle[i]-'a'));
            }
            int subset=mask;
            do{
                int s=subset|(1<<(puzzle[0]-'a'));
                if(fre.count(s))tot+=fre[s];
                subset=(subset-1)&mask;
            }while(subset!=mask);
            ans.push_back(tot);
        }
        return ans;
    }
};