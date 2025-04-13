#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<string> words;
string line;
set<string> s;
int main(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> line;
    words.push_back(line);
  }
  string makeWord = "";
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
        if(words[i][j] != '#'){
            makeWord += words[i][j];
        }
        else{
            if(makeWord.length() > 1)
                s.insert(makeWord);
            makeWord = "";
        }
    }
    if(makeWord.length() > 1)
      s.insert(makeWord);
    makeWord = "";
  }
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
        if(words[j][i] != '#'){
            makeWord += words[j][i];
        }
        else{
            if(makeWord.length() > 1)
              s.insert(makeWord);
            makeWord = "";
        }
    }
    if(makeWord.length() > 1)
      s.insert(makeWord);
    makeWord = "";
  }
  cout << *s.begin() << '\n';
  return 0;
}