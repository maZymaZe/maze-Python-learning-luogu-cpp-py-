#include <cstdio>
#include <iostream>
using namespace std; 
int n, a[1030] = {1};
int main()
{
   
    cin>>n;
      for(int i=0;i<1<<n;++i){
        for(int j=1;j<(1<<n)-i;++j)cout<<" ";//前导空格
        for(int j=i;j>=0;--j)a[j]^=a[j-1];//修改数组
        if(!(i%2))for(int j=0;j<=i;++j)cout<<(a[j]?"/\\":"  ");//奇数行
        else for(int j=0;j<=i;j+=2)cout<<(a[j]?"/__\\":"    ");//偶数行
        cout << endl;
    }
    return 0;
}