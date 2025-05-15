#include<bits/stdc++.h>
using namespace std;

int n, num, result= 999999999;
vector<int> a, b;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> num;
    a.push_back(num);
  }
  for (int i = 0; i < n; i++){
    cin >> num;
    b.push_back(num);
  }
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  int num2 = 0;
  for (int i = 0; i < n; i++){
    num2 += a[i] * b[i];
  }
  result = min(num2, result);
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());
  num2 = 0;
  for (int i = 0; i < n; i++){
    num2 += a[i] * b[i];
  }
  result = min(num2, result);
  cout << result;
  return 0;
}