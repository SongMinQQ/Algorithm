#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int g;
vector<int> result, arr;
void make(){
  for(int i = 1; i <= g+20; i++){
    arr.push_back(i);
  }
}
int main(){
  cin >> g;
  make();
  int idx1 = 0, idx2 = 1;
  while(idx1 < idx2){
    ll sum = abs(arr[idx1] - arr[idx2]) * (arr[idx1] + arr[idx2]);
    if(sum == g){
      result.push_back(arr[idx2]);
      // idx1++;
      idx2++;
    }
    else if(sum < g)idx2++;
    else idx1++;
  }
  sort(result.begin(),result.end());
  if(result.size()){
    for(int i : result) cout << i << '\n';
  }
  else cout << -1 << '\n';
  return 0;
}