#include<bits/stdc++.h>
using namespace std;

string a;
int n, res, res2;

int recursion(string& s, int l, int r){
  res++;
  if (l >= r) return 1;
  else if (s[l] != s[r]) return 0;
  else return recursion(s, l + 1, r - 1);
}
int isPalindrome(string& s){
  return recursion(s, 0, s.size() - 1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while(n--){
    res = 0;
    cin >> a;
    res2 = isPalindrome(a);
    cout << res2 << ' ' << res << '\n';
  }
  return 0;
}