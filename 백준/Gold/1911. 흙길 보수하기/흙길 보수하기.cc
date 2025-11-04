#include<bits/stdc++.h>
using namespace std;
int n, l, num1, num2, ret, last = -1;
vector<pair<int, int>> v;

int main(){
  cin >> n >> l;
  for (int i = 0; i < n; i++){
    cin >> num1 >> num2;
    v.push_back({num1, num2});
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++){
    int s = v[i].first, e = v[i].second;
    if(last < s) last = s;
    if(last >= e) continue;
    int board = ceil((e - last + l - 1) / l);
    ret += board;
    last += board * l;
  }
  cout << ret;
  return 0;
}