#include<bits/stdc++.h>
using namespace std;

string a;
bool hasZero;
long long sum;
int main(){
  cin >> a;
  for (char c : a) {
    sum += (c - '0');
    if (c == '0') hasZero = true;
  }
  if (!hasZero || sum % 3 != 0) {
    cout << -1;
    return 0;
  }
  sort(a.rbegin(), a.rend());
  cout << a;
  return 0;
}