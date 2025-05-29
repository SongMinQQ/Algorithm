#include<bits/stdc++.h>
using namespace std;

int t, a, b, c;
int main(){
  cin >> t;
  while(t--){
    cin >> a >> b;
    c = 1;
    for (int i = 0; i < b; i++){
      c *= a;
      c %= 10;
    }
      
    c != 0 ? cout << c << '\n' : cout << 10 << '\n';
  }
  return 0;
}