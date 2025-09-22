#include<bits/stdc++.h>
using namespace std;

string a, b;
int cnt, cnt2;
int main(){
  cin >> a;
  for(char i : a){
    if(i == 'a')
      cnt++;
  }
  for (int i = 0; i < cnt; i++){
    if(a[i] == 'b')
      cnt2++;
  }
  int ret = cnt2;
  b = a + a;
  for (int i = cnt; i < a.size() + cnt; i++){
    if(b[i - cnt] == 'b')
      cnt2--;
    if(b[i] == 'b')
      cnt2++;
    ret = min(ret, cnt2);
  }
  cout << ret;
  return 0;
}