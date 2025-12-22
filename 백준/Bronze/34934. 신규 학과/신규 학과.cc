#include<bits/stdc++.h>
using namespace std;
int n, a;
string b, ret;
int main(){
  cin >> n;
  while(n--){
    cin >> b >> a;
    if(a == 2026){
      ret = b;
    }
  }
  cout << ret;
  return 0;
}