#include<bits/stdc++.h>
using namespace std;

vector<int> a, b;
int n, n1, n2;
int main(){
  cin >> n;
  while(n--){
    cin >> n1 >> n2;
    a.push_back(n1);
    b.push_back(n2);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  a.size() == 1 ? cout << 0 : cout << (a[a.size() - 1] - a[0]) * (b[b.size() - 1] - b[0]);
  return 0;
}