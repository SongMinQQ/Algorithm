#include<bits/stdc++.h>
using namespace std;

vector<int> v[1002];
int n, num, ret, result;
int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 5; j++){
      cin >> num;
      v[i].push_back(num);
    }
  }
  for (int i = 0; i < n; i++){
    int a = 0;
    bool visited[n];
    fill(&visited[0], &visited[n], 0);
    for (int j = 0; j < 5; j++){
      int curNum = v[i][j];
      for (int k = 0; k < n; k++){
        if(k == i) continue;
        if(v[k][j] == curNum)
          visited[k] = 1;
      }
    }
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if(visited[j]) cnt++;
    }
    if(ret < cnt){
      ret = cnt;
      result = i + 1;
    }
  }
  result == 0 ? cout << 1 : cout << result;
  return 0;
}