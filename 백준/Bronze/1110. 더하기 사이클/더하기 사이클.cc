#include<bits/stdc++.h>
using namespace std;

int a;
int ret, cnt, b, c;
int main(){
  cin >> a;
  if(a == 0){
    cout << 1;
    return 0;
  }
  // 10의 자리수
  b = a / 10;
  // 1의 자리수
  c = a - (10 * b);
  while (ret != a){
    ret = b + c;
    ret -= ((ret / 10) * 10);
    ret += c * 10;
    b = ret / 10;
    c = ret - (10 * b);
    cnt++;
  }
  cout << cnt;
  return 0;
}