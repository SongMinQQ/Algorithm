#include<bits/stdc++.h>
using namespace std;

int n, m;
string line;
unordered_set<string> memo;

vector<string> split(string input, string delimiter){
  vector<string> ret;
  long long pos = 0;
  string token;
  while((pos = input.find(delimiter)) != string::npos){
    token = input.substr(0, pos);
    ret.push_back(token);
    input.erase(0, pos + delimiter.size());
  }
  ret.push_back(input);
  return ret;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  while(n--){
    cin >> line;
    memo.insert(line);
  }
  while(m--){
    cin >> line;
    vector<string> v = split(line, ",");
    for(string i : v){
      memo.erase(i);
    }
    cout<< memo.size() << '\n';
  }
  return 0;
}