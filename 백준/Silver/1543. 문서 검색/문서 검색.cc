#include<bits/stdc++.h>
using namespace std;

string line, word;
int result;
int main(){
  getline(cin, line);
  getline(cin, word);
  int pos = 0;
  while((pos = line.find(word)) != string::npos){
    line = line.erase(0, pos + word.length());
    result++;
  }
  cout << result;
  return 0;
}