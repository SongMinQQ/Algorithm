#include <bits/stdc++.h>
using namespace std;

int t, k, num1, num2, ret;
deque<int> dq[1004];

void rotateLeft(deque<int> &d){
  d.push_back(d.front());
  d.pop_front();
}
void rotateRight(deque<int> &d){
  d.push_front(d.back());
  d.pop_back();
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  for (int i = 0; i < t; i++){
    string line;
    cin >> line;
    for (char j : line)
      dq[i].push_back(j - '0');
  }

  cin >> k;
  while (k--){
    cin >> num1 >> num2;
    num1--;

    vector<int> leftTooth(t), rightTooth(t);
    for (int i = 0; i < t; i++){
      leftTooth[i] = dq[i][6];
      rightTooth[i] = dq[i][2];
    }

    vector<int> dir(t, 0);
    dir[num1] = num2;

    for (int i = num1 - 1; i >= 0; --i){
      if (rightTooth[i] == leftTooth[i + 1])
        break;
      dir[i] = -dir[i + 1];
    }
    for (int i = num1 + 1; i < t; ++i){
      if (rightTooth[i - 1] == leftTooth[i])
        break;
      dir[i] = -dir[i - 1];
    }

    for (int i = 0; i < t; i++){
      if (dir[i] == 1)
        rotateRight(dq[i]);
      else if (dir[i] == -1)
        rotateLeft(dq[i]);
    }
  }

  for (int i = 0; i < t; i++){
    if (dq[i][0] == 1)
      ret++;
  }
  cout << ret << '\n';
  return 0;
}
