#include<bits/stdc++.h>
using namespace std;

int n, a, b, result;
vector<pair<int,int>> egg;
void dfs(int cur, int brokenCount) {
  if (cur == n) {
      result = max(result, brokenCount);
      return;
  }

  if (egg[cur].first <= 0) {
      dfs(cur + 1, brokenCount);
      return;
  }
  
  bool hitPossible = false;
  for (int i = 0; i < n; i++) {
      if (i == cur || egg[i].first <= 0) continue;
      
      hitPossible = true;
      int originalCur = egg[cur].first;
      int originalI = egg[i].first;
      int tempBroken = 0;
      egg[cur].first -= egg[i].second;
      egg[i].first -= egg[cur].second;

      if (egg[cur].first <= 0) tempBroken++;
      if (egg[i].first <= 0) tempBroken++;

      dfs(cur + 1, brokenCount + tempBroken);
      egg[cur].first = originalCur;
      egg[i].first = originalI;
  }
  if (!hitPossible) {
      dfs(cur + 1, brokenCount);
  }
}
int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    egg.push_back({a,b});
  }
  dfs(0,0);
  cout << result << '\n';
  return 0;

}