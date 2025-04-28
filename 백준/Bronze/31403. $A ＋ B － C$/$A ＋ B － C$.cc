#include<bits/stdc++.h>
using namespace std;

int a, b, c;
int main(){
  cin >> a >> b >> c;
  string s = to_string(a) + to_string(b);
  int ab = stoi(s);
  cout << a + b - c << '\n' << (ab - c) << '\n';
  return 0;
}