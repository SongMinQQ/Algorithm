#include<bits/stdc++.h>
using namespace std;

int n, m, num;
vector<int> v;
set<vector<int>> ret;
void go(int s, vector<int> ve){
  if(ve.size() == m){
    ret.insert(ve);
    return;
  }
  for (int i = s; i < n; i++){
    ve.push_back(v[i]);
    go(i + 1, ve);
    ve.pop_back();
  }
}
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> num;
    v.push_back(num);
  }
  sort(v.begin(), v.end());
  vector<int> v2;
  go(0, v2);
  for(vector<int> i : ret){
    for (int j = 0; j < i.size(); j++){
      cout << i[j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}