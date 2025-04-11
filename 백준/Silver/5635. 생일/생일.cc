#include<bits/stdc++.h>
using namespace std;
typedef tuple<int, int, pair<int, string>> tp;
int n;
string line;
vector <tp> v;
vector<string> split(string input, string delimiter){
  vector<string> result;
  long long pos = 0;
  string token;
  while((pos = input.find(delimiter)) != string::npos){
    token = input.substr(0, pos);
    result.push_back(token);
    input.erase(0,pos + delimiter.length());
  }
  result.push_back(input);
  return result;
}
bool cmp(tp a, tp b) {
  if(get<0>(a) != get<0>(b))
    return get<0>(a) < get<0>(b);
  if(get<1>(a) != get<1>(b))
    return get<1>(a) < get<1>(b);
  return get<2>(a).first < get<2>(b).first;
}


int main(){
  cin >> n;
  cin.ignore();
  while(n--){
    getline(cin, line);
    vector<string> info = split(line, " ");
    int year = stoi(info[3]), month = stoi(info[2]), day = stoi(info[1]);
    string name = info[0];
    v.push_back({year, month, {day, name}});
  }
  sort(v.begin(),v.end(), cmp);
    cout << get<2>(v[v.size() - 1]).second << '\n' << get<2>(v[0]).second << '\n';
  return 0;
}