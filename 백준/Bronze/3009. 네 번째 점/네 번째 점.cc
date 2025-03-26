#include<bits/stdc++.h>
using namespace std;
int a, b, cnt1, cnt2;
int main(){
  int cnt = 2;
  cin >> a >> b;
  int bak1 = a, bak2 = b, aa, bb;
  while(cnt--){
    cin >> a >> b;
    if(a == bak1) cnt1++;
    else aa = a;
    if(b == bak2) cnt2++;
    else bb = b;
  }
  cnt1 ? cout << aa << ' ' : cout << bak1 << ' ';
  cnt2 ? cout << bb : cout << bak2;
  return 0;
}