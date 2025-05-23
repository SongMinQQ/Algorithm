#include<bits/stdc++.h>
using namespace std;

string s;
vector<string> v;
int n;
int main(){
  cin >> n;
  cin.ignore();
  for (int i = 0; i < n; i++){
    getline(cin, s);
    v.push_back(s);
  }
  for (int i = 0; i < n; i++){
    cout << i + 1 << ". " << v[i] << '\n';
  }
  return 0;
}