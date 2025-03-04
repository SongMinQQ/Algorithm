#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<pair<ll, ll>> v;
int n, num1, num2;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> num1 >> num2;
    v.push_back({num1, num2});
  }
  sort(v.begin(),v.end());
  int s = v[0].first;
  int e = v[0].second;
  int result = 0;
  for (int i = 1; i < n; i++)
	{
		if (v[i].second < e) continue;
		else{
			if (v[i].first > e){
				result += e - s;
				s = v[i].first;
			}
			e = v[i].second;
		}
	}
	result += e - s;
	cout << result << '\n';
  return 0;
}