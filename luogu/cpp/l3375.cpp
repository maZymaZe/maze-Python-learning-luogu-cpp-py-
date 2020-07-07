#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> result, Next;

void kmp(const string& Text, const string& Pattern) {
    int LengthOfText = Text.size(), LengthOfPattern = Pattern.size();
    Next.resize(LengthOfPattern);
    Next[0] = -1;
    for (int i = 1; i < LengthOfPattern; i++) {
        int j = Next[i - 1];
        while (Pattern[j + 1] != Pattern[i] && j >= 0) {
            j = Next[j];
        }
        if (Pattern[j + 1] == Pattern[i]) {
            Next[i] = j + 1;
        } else {
            Next[i] = -1;
        }
    }

    int PointerOfText = 0, PointerOfPattern = 0;
    while (PointerOfText < LengthOfText) {
        if (Text[PointerOfText] == Pattern[PointerOfPattern]) {
            PointerOfText++;
            PointerOfPattern++;
        } else {
            if (PointerOfPattern == 0)
                PointerOfText++;
            else {
                PointerOfPattern = Next[PointerOfPattern-1]+1;
            }
        }
        if (PointerOfPattern == LengthOfPattern) {
            result.push_back(PointerOfText - LengthOfPattern + 1);
            PointerOfPattern = Next[PointerOfPattern - 1] + 1;
        }
    }
}
int main(){
    string Text,Pattern;
    cin>>Text>>Pattern;
    kmp(Text,Pattern);
    for(int i=0;i<result.size();i++){
        printf("%d\n",result[i]);
    }
    printf("0 ");
    for(int i=1;i<Pattern.size();i++){
        printf("%d ",Next[i]+1);
    }
    return 0;
}
