#include<bits/stdc++.h>
using namespace std;

int n, x, num, cnt;
vector<int> v;
// vector<pair<int,int>> result;
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(),v.end());
  cin >> x;
  int idx1 = 0, idx2 = v.size() - 1, sum = 0;
  while(idx1 < idx2){
    sum = v[idx1] + v[idx2];
    if(sum == x) {
      cnt++;
      idx1++;
      idx2--;
    }
    if(sum > x){
      idx2--;
    }
    if(sum < x){
      idx1++;
    }
  }
  cout << cnt;
  return 0;
}