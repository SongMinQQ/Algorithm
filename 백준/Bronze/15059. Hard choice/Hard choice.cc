#include<bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f, ret;
int main(){
  cin >> a >> b >> c >> d >> e >> f;
  int q = d - a, w = e - b, r = f - c;
  if (q > 0)
    ret += abs(q);
  if(w > 0) ret += abs(w);
  if(r > 0) ret += abs(r);
  cout << ret;
  return 0;
}