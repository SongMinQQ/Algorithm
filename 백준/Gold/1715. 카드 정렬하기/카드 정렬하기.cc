#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n, result, token;
int main(){
  cin >> n;
  vector<int> cards(n);
  for (int i = 0; i < n; i++){
    cin >> cards[i];
    pq.push(cards[i]);
  }
  /*
  우선순위 큐에 다 때려넣음
  2개씩 카드덱을 합침
  합친값을 pq에 넣음
  카드 합친거만 결과에 더함
  이걸 사이즈 1이 될때까지 반복
  */
  while(pq.size()!= 1){
    int num1, num2, num3;
    num1 = pq.top();
    pq.pop();
    num2 = pq.top();
    num3 = num1 + num2;
    result += num3;
    pq.pop();
    pq.push(num3);
  }

  cout << result;
  return 0;
}