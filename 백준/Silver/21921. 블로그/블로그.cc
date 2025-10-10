#include<bits/stdc++.h>
using namespace std;

int x, n, num, s, ret, cnt;
vector<int> prefix;

int main(){
  cin >> x >> n;
  prefix.push_back(0);
  for (int i = 0; i < x; i++){
    cin >> num;
    s += num;
    prefix.push_back(s);
  }
  for (int i = n; i <= x; i++){
    int sum = prefix[i] - prefix[i - n];
    if(sum > ret){
      ret = sum;
      cnt = 1;
    }
    else if(sum == ret){
      cnt++;
    }
  }
  ret == 0 ? cout << "SAD" : cout << ret << '\n' << cnt;
  return 0;
}