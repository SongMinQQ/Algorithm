#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<string, priority_queue<int>> ump;
string name;
ll n, num, k, b, c, ret;
void push_num(string n, vector<int> v){
  for (int i = 0; i < v.size(); i++){
    ump[n].push(v[i]);
  }
}
void cal(string n, int a){
  for (int i = 0; i < a; i++){
    if(ump[n].empty())
      return;
    ret += ump[n].top();
    ump[n].pop();
  }
}
int main(){
  cin >> n;
  while(n--){
    cin >> num;
    if(num == 1){
      vector<int> ve;
      cin >> name >> k;
      for (int i = 0; i < k; i++){
        cin >> c;
        ve.push_back(c);
      }
      push_num(name, ve);
    }
    else{
      cin >> name >> b;
      cal(name, b);
    }
  }
  cout << ret;
  return 0;
}