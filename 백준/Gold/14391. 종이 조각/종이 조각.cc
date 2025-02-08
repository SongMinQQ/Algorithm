#include <bits/stdc++.h>
using namespace std;

int n, m, paper[5][5], result = 0;
int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%1d",&paper[i][j]);
    }
  }
  /*
    가로 0 세로 1
    2차원 배열을 1차원으로 생각할 것
    4*4 배열의 경우 16만큼 shift 즉
    0000 / 0000 / 0000 / 0000 부터
    1111 / 1111 / 1111 / 1111 까지 모든 경우의 수를 탐색함
    */
    // cout << i << '\n';
  for(int i = 0; i < (1 << n * m); i++){
    int sum = 0;
    //가로
    for(int j = 0; j < n; j++){
      int cur = 0;
      for(int k = 0; k < m; k++){
        int l = j * m + k;
        if((i & (1 << l)) != 0){
          // cout << "cur : " << cur << '\n';
          sum += cur;
          // cout << "sum : " << sum << '\n';
          cur = 0;
        }
        else{
          cur = cur * 10 + paper[j][k];
          // cout << "cur : " << cur << '\n';
        }
      }
      /* 각 행의 마지막 칸까지 진행한 후에도, 만약 마지막에 
      가로 조각이 이어지고 있었다면 그 숫자 조각을 결과에 반영 */
      sum += cur;
    }
    // result = result > sum ? result : sum;
    // sum = 0;
    for(int j = 0; j < m; j++){
      int cur = 0;
      for(int k = 0; k < n; k++){
        int l = k * m + j;
        if((i & (1 << l)) == 0){
          sum += cur;
          cur = 0;
        }
        else{
          cur = cur * 10 + paper[k][j];
          // cout << cur << '\n';
        }
      }
      sum += cur;
      // cur = 0;
    }
    // cout << sum << '\n';
    result = max(result, sum);
  }
  /*
  4 4
  0001
  0000
  0000
  1001

  => 1101
  */
  cout << result;
  return 0;
}