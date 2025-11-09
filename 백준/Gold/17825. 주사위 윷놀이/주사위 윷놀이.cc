#include<bits/stdc++.h>
using namespace std;

vector<int> adj[55];
int v[103], dice[12], mal[4] = {0};
void add(int h, int t){
  adj[h].push_back(t);
}
void setMap(){
  for (int i = 0; i < 20; i++) add(i, i + 1);
  add(5,21);add(21,22);add(22,23);add(23,24);
  add(10,27);add(27,28);add(28,24);
  add(15,29);add(29,30);add(30,31);add(31,24);
  add(24,25);add(25,26);add(26, 20);add(20, 100);
  for (int i = 1; i <= 20; i++) v[i] = i * 2;
  v[21] = 13;v[22] = 16; v[23] = 19;v[24] = 25;
  v[25] = 30;v[26] = 35; v[27] = 22;v[28] = 24;
  v[29] = 28;v[30] = 27;v[31] = 26; 
}

int move(int here, int cnt){
  // cout << here << ' ' << cnt << '\n';
  if(here == 100)return 100;
  if(adj[here].size() >= 2){
    here = adj[here][1];
    cnt--;
  }
  if(cnt){
    queue<int> q;
    q.push(here);
    int there;
    while(q.size()){
      int x = q.front();
      q.pop();
      there = adj[x][0];
      // cout << there << '\n';
      q.push(there);
      if(there == 100) break;
      cnt--;
      if(cnt == 0) break;
    }
    return there;
  }
  else
    return here;
}
bool isMal(int idx, int no){
  if(idx == 100) return false;
  for (int i = 0; i < 4; i++){
    if(i == no)continue;
    if(mal[i] == idx) return true;
  }
  return false;
}
int go(int here){
  // cout << here << '\n';
  if(here == 10) return 0;
  int ret = 0;
  for (int i = 0; i < 4; i++){
    int temp_idx = mal[i];
    int mal_idx = move(temp_idx, dice[here]);
    // cout << temp_idx << ' ' << mal_idx << ' ' << i << '\n';

    if(isMal(mal_idx, i)) continue;
    mal[i] = mal_idx;
    ret = max(ret, go(here + 1) + v[mal_idx]);
    mal[i] = temp_idx;
  }
  return ret;
}
int main(){
  setMap();
  for (int i = 0; i < 10; i++) cin>> dice[i];
  cout << go(0);
  return 0;
}