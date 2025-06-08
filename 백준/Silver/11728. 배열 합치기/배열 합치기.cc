#include<bits/stdc++.h>
using namespace std;

int a, b;
vector<int> v;

int main(){
  cin >> a >> b;
  int c = a + b, num;
  while(c--){
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  for(int i : v){
    cout << i << ' ';
  }
  return 0;
}