#include<cstdio>
#include<vector>
#include<iostream>
#include<deque>
using namespace std;
int main(){
    int n,k,t;
    vector<int> value;
    deque<int> indexb,indexs;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        value.push_back(t);
    }
    printf("0\n");
    for(int i=0;i<n-1;i++){
        if(!indexs.empty()){
            if(indexs.front()<=i-k)indexs.pop_front();
            if(indexs.empty())indexs.push_back(i);
            else{
                t=indexs.size();
                for(int j=t-1;j>=0;j--){
                    if(value[indexs.back()]>=value[i]){
                        indexs.pop_back();
                    }
                    else{
                        indexs.push_back(i);
                        break;
                    }
                }
                if(indexs.empty())indexs.push_back(i);
            }
        }
        else indexs.push_back(i);
        printf("%d\n",value[indexs.front()]);
    }
    
    return 0;
}