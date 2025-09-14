#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n, num;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  if (!prev_permutation(v.begin(), v.end())){
    cout << -1;
    return 0;
  }
  for (int x : v)
    cout << x << ' ';
  return 0;
}