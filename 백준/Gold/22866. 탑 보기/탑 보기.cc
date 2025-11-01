#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  vector<int> h(n+1);
  for (int i = 1; i <= n; i++) cin >> h[i];

  vector<int> leftCnt(n+1, 0), leftNear(n+1, -1);
  stack<int> st; 

  for (int i = 1; i <= n; i++){
    while(!st.empty() && h[st.top()] <= h[i]) st.pop();
    leftCnt[i] = (int)st.size();
    if(!st.empty()) leftNear[i] = st.top();
    st.push(i);
  }
  
  vector<int> rightCnt(n+1, 0), rightNear(n+1, -1);
  {
    stack<int> st;
    for (int i = n; i >= 1; --i){
      while(!st.empty() && h[st.top()] <= h[i]) st.pop();
      rightCnt[i] = (int)st.size();
      if(!st.empty()) rightNear[i] = st.top();
      st.push(i);
    }
  }

  for (int i = 1; i <= n; i++){
    int cnt = leftCnt[i] + rightCnt[i];
    if (cnt == 0){
      cout << 0 << '\n';
      continue;
    }
    int L = leftNear[i]; 
    int R = rightNear[i];
    int pick = -1;
    if (L == -1) pick = R;
    else if (R == -1) pick = L;
    else{
      int dl = i - L;
      int dr = R - i;
      if (dl < dr) pick = L;
      else if (dr < dl) pick = R;
      else pick = min(L, R);
    }
    cout << cnt << ' ' << pick << '\n';
  }
  return 0;
}
