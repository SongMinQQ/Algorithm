#include<bits/stdc++.h>
using namespace std;
int k, l, num = 1;
string line;
map<string, int> m;
int main(){
  cin >> k >> l;
  for (int i = 0; i < l; i++){
    cin >> line;
    m[line] = num++;
  }
  vector<pair<string, int>> mVec(m.begin(), m.end());
  sort(mVec.begin(), mVec.end(), [](const pair<string, int>& a, const pair<string, int>& b){
    return a.second < b.second;
  });
  vector<string> ret;
  for (auto i : mVec){
    ret.push_back(i.first);
    if(ret.size() == k) break;
  }
  for (auto i : ret){
    cout << i << "\n";
  }
  return 0;
}