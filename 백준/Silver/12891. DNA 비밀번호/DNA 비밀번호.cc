#include<bits/stdc++.h>
using namespace std;

int s, p, ret, checkArr[4];
string st;
const char words[] = {'A', 'C', 'G', 'T'};
int main(){
  cin >> s >> p >> st;
  for (int i = 0; i < 4; i++){
    cin >> checkArr[i];
  }
  unordered_map<char, int> ump;
  int l = 0;
  for (int i = 0; i < p; i++){
    if (st[i] == 'A' || st[i] == 'C' || st[i] == 'G' || st[i] == 'T'){
      ump[st[i]]++;
    }
  }
  int cnt = 0;
  for (int j = 0; j < 4; j++){
    if (ump[words[j]] >= checkArr[j])
    {
      cnt++;
    }
    if (cnt == 4)
      ret++;
  }
  for (int i = p; i < s; i++){
    cnt = 0;
    if (st[l] == 'A' || st[l] == 'C' || st[l] == 'G' || st[l] == 'T'){
      if(ump[st[l]] > 0)
      ump[st[l]]--;
    }
    if (st[i] == 'A' || st[i] == 'C' || st[i] == 'G' || st[i] == 'T')
    {
      ump[st[i]]++;
    }
    for (int j = 0; j < 4; j++){
      if (ump[words[j]] >= checkArr[j]){
        cnt++;
      }
    }
    if (cnt == 4)
      ret++;
    l++;
  }
  cout << ret;
  return 0;
}