#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, result = 99999999;
vector<int> c, d;
int main(){
  cin >> n >> m;
  while(m--){
    cin >> a >> b;
    c.push_back(a);
    d.push_back(b);
  }
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());
  int e = n / 6, f = ceil(n / 6.0), g = n % 6;
  int sum1 = c[0] * f, sum2 = d[0] * n, sum3 = (c[0] * e) + (d[0] * g);
  sum1 < sum2 ? result = min(sum1, sum3) : result = min(sum2, sum3);
  cout << result;
  return 0;
}