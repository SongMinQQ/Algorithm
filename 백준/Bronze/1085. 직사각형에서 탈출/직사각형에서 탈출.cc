#include<bits/stdc++.h>
using namespace std;

int x, y, w, h;
vector<int> v;
int main(){
  cin >> x >> y >> w >> h;
  v.push_back(abs(0 - x));
  v.push_back(abs(0 - y));
  v.push_back(abs(w - x));
  v.push_back(abs(h - y));
  sort(v.begin(),v.end());
  cout << v[0] << '\n';
  return 0;
}