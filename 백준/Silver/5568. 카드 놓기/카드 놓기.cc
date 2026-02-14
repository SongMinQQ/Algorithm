#include<bits/stdc++.h>
using namespace std;
int n, k;
string num;
vector<string> nums;
set<string> s;
bool visited[12];
void go(vector<string> a){
  if(a.size() == k){
    string ret = "";
    for(string i : a){
      ret += i;
    }
    // cout << ret << '\n';
    s.insert(ret);
    return;
  }
  for (int i = 0; i < n; i++){
    if(!visited[i]){
      a.push_back(nums[i]);
      visited[i] = 1;
      go(a);
      a.pop_back();
      visited[i] = 0;
    }
  }
}
int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> num;
    nums.push_back(num);
  }
  vector<string> v;
  go(v);
  cout << s.size();
  return 0;
}