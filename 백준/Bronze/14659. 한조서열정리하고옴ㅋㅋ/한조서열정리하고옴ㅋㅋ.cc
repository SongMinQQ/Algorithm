#include<bits/stdc++.h>
using namespace std;
int ret, n, num, cnt, high;
int main(){
  cin >> n;
  cin >> high;
  n--;
  while(n--){
    cin >> num;
    if(num > high){
      ret = max(ret, cnt);
      cnt = 0;
      high = num;
    }
    else
      cnt++;
  }
  ret = max(ret, cnt);
  cout << ret;
  return 0;
}