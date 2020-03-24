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
    for(int i=0;i<n;i++){
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
        if(i>=k-1)printf("%d ",value[indexs.front()]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        if(!indexb.empty()){
            if(indexb.front()<=i-k)indexb.pop_front();
            if(indexb.empty())indexb.push_back(i);
            else{
                t=indexb.size();
                for(int j=t-1;j>=0;j--){
                    if(value[indexb.back()]<=value[i]){
                        indexb.pop_back();
                    }
                    else{
                        indexb.push_back(i);
                        break;
                    }
                }
                if(indexb.empty())indexb.push_back(i);
            }
        }
        else indexb.push_back(i);
        if(i>=k-1)printf("%d ",value[indexb.front()]);
    }
    return 0;
}