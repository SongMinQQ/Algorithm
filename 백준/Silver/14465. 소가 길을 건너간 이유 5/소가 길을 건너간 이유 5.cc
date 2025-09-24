#include<bits/stdc++.h>
using namespace std;

bool check[100002];
int n, k, b, num, ret;
int main(){
  cin >> n >> k >> b;
  for (int i = 0; i < b; i++){
    cin >> num;
    check[num] = true;
  }
  int cnt = 0, l = 1;
  for (int i = 1; i <= k; i++){
    if(check[i])
      cnt++;
  }
  ret = cnt;
  for (int i = k + 1; i <= n; i++){
    if(check[l]){
      cnt--;
    }
    if(check[i]){
      cnt++;
    }
    ret = min(ret, cnt);
    l++;
  }
  cout << ret;
  return 0;
}