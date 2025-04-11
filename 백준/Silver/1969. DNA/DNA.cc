#include<bits/stdc++.h>
using namespace std;

vector<string> v;
vector<char> result;
string line;
int n, m, resultCnt;
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> line;
    v.push_back(line);
  }
  for (int i = 0; i < m; i++){
    map<char, int> mp;
    int cnt = 0;
    char dna;
    for (int j = 0; j < n; j++){
      if(mp.find(v[j][i]) != mp.end()){
        mp[v[j][i]]++;
      }
      else
        mp.insert({v[j][i], 1});
    }
    for(auto j : mp){
      if(j.second > cnt){
        cnt = j.second;
        dna = j.first;
      }
    }
    // cout << "i : " << i << ' ' << n - cnt << '\n';
    resultCnt += (n - cnt);
    result.push_back(dna);
  }
  for(char i : result)
    cout << i;
  cout << '\n' << resultCnt << '\n';
  return 0;
}