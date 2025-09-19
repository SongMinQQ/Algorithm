#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int n, num;
int main(){
  cin >> n;
  while(n--){
    cin >> num;
    v.push_back(num);
  }
  if(next_permutation(v.begin(), v.end())){
    for(int i : v){
      cout << i << ' ';
    }
  }
  else
    cout << -1;
  return 0;
}