#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s, n = 1, cnt = 0, num = 0;
int main()
{
    cin >> s; 
    while(1){
        num+=1;
        if(s-cnt-num>num){
            n+=1;
            cnt+=num;
        }
        else{
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}