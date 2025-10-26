#include<bits/stdc++.h>
using namespace std;

int n, s, num, ret, cnt;
vector<int> v;
void go(int st, int sum){
  if(sum == s){
    cnt++;
  }
  int a = sum;
  for (int i = st; i < n; i++){
    a += v[i];
    go(i + 1, a);
    a -= v[i];
  }
}
int main(){
  cin >> n >> s;
  for (int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  go(0, 0);
  if (s == 0) cnt -= 1;
  cout << cnt;
  return 0;
}