#include<bits/stdc++.h>
using namespace std;

int n, result;
vector<int> rope;
int main(){
  cin >> n;
  int a;
  for(int i = 0; i < n; i++){
    cin >> a;
    rope.push_back(a);
  }
  sort(rope.begin(), rope.end());
  result = rope[0];
  int current;
	for (int i = 0; i < n; i++) {
		current = rope[i] * (n - i);
    result = max(result, current);
	}

	cout << result;
}