#include<bits/stdc++.h>
using namespace std;

int n, r[20][20], eun, cnt, diff[20], ret;
vector<int> v;
bool dead[20];

int kill(){
  int findMax = 0;
  for (int i = 0; i < n; i++){
    if(dead[i]) continue;
    findMax = max(v[i] + diff[i], findMax);
  }
  for (int i = 0; i < n; i++){
    if(dead[i]) continue;
    if (v[i] + diff[i]== findMax){
      //죽었다는 처리를 어떻게 할것인지?
      return i;
    }
  }
}
/**
 * turn : 마피아 제외 죽은사람 수(몇 밤을 보냈나)
 * cur : 현재 짝수날인지 홀수날인지 판별용
 */
void mafia(int turn, int cur){
  if(dead[eun] || cur == 1){
    ret = max(ret, turn);
    return;
  }
  // 현재 짝수날이 아니라면
  if(cur % 2 != 0){
    int killIdx = kill();
    dead[killIdx] = 1;
    cur--;
    mafia(turn, cur);
    dead[killIdx] = 0;
    return;
  }
  for (int i = 0; i < n; i++){
    if(i == eun || dead[i]){
      continue;
    }
    dead[i] = 1;
    for (int j = 0; j < n; j++){
      diff[j] += r[i][j];
    }
    turn++;
    cur--;
    mafia(turn, cur);
    dead[i] = !dead[i];
    turn--;
    cur++;
    for (int j = 0; j < n; j++){
      diff[j] -= r[i][j];
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> r[i][j];
    }
  }
  cin >> eun;
  mafia(0, n);
  cout << ret;
  return 0;
}