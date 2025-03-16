#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int N;
  cin >> N;
  string s;
  cin >> s;
  
  // 이미 모든 볼이 같은 색이면 정답은 0
  bool allSame = true;
  for (int i = 1; i < N; i++){
      if(s[i] != s[0]){
          allSame = false;
          break;
      }
  }
  if(allSame){
      cout << 0 << "\n";
      return 0;
  }
  
  // 각 색의 총 개수를 센다.
  int totalR = 0, totalB = 0;
  for (char c : s) {
      if(c == 'R') totalR++;
      else totalB++;
  }
  
  // 왼쪽에서 연속으로 있는 R와 B의 개수를 센다.
  int leftR = 0, leftB = 0;
  for (int i = 0; i < N; i++){
      if(s[i] == 'R') leftR++;
      else break;
  }
  for (int i = 0; i < N; i++){
      if(s[i] == 'B') leftB++;
      else break;
  }
  
  // 오른쪽(끝)에서 연속으로 있는 R와 B의 개수를 센다.
  int rightR = 0, rightB = 0;
  for (int i = N-1; i >= 0; i--){
      if(s[i] == 'R') rightR++;
      else break;
  }
  for (int i = N-1; i >= 0; i--){
      if(s[i] == 'B') rightB++;
      else break;
  }
  int moveR = min(totalR - leftR, totalR - rightR);
  int moveB = min(totalB - leftB, totalB - rightB);
  
  // 두 색 중 더 적은 이동 횟수가 정답
  int answer = min(moveR, moveB);
  
  cout << answer << "\n";
  return 0;
}
