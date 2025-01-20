#include <bits/stdc++.h>
using namespace std;

string s;
int n, sum[26][200002], l, r;
char a;

int main()
{
  cin >> s >> n;
  for (int j = 0; j < (int)s.size(); j++)
  {
    int c = s[j] - 'a';
    for (int i = 0; i < 26; i++)
    {
      sum[i][j + 1] = sum[i][j];
    }
    sum[c][j + 1]++;
  }
  for (int i = 0; i < n; i++)
  {
    cin >> a >> l >> r;
    int idx = a - 'a';
    cout << sum[idx][r + 1] - sum[idx][l] << "\n";
  }
  return 0;
}