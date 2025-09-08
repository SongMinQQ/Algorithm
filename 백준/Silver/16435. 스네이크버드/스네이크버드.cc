#include<bits/stdc++.h>
using namespace std;

int n, l, num;
vector<int> v;

int main(){
  cin >> n >> l;
  for(int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  for(int i : v){
    if(l >= i){
      l++;
    }
  }
  cout << l;
  return 0;
}