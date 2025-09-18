#include<bits/stdc++.h>
using namespace std;

int n, m;
string a, b;
map<string, string> mp;

vector<string> split(string input, string delimiter){
  vector<string> ret;
  long long pos = 0;
  string token = "";
  while((pos = input.find(delimiter)) != string::npos){
    token = input.substr(0, pos);
    ret.push_back(token);
    input.erase(0, pos + delimiter.length());
  }
  ret.push_back(input);
  return ret;
}
int main(){
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin.ignore();
  for (int i = 0; i < n; i++){
    getline(cin, a);
    vector<string> c = split(a, " ");
    mp[c[0]] = c[1];
  }
  for (int i = 0; i < m; i++){
    cin >> b;
    cout << mp[b] << '\n';
  }
  return 0;
}