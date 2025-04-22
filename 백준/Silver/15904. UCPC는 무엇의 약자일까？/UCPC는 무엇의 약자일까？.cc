#include<bits/stdc++.h>
using namespace std;

string line;
map<char, int> m;
int main(){
  getline(cin, line);
  string target = "UCPC";
  int idx = 0;
  for (char ch : line) {
    if (idx < 4 && ch == target[idx]) {
      idx++;
    }
  }
  if (idx == 4)
      cout << "I love UCPC\n";
  else
      cout << "I hate UCPC\n";
  return 0;
}