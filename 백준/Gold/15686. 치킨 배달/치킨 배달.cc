#include <bits/stdc++.h>
using namespace std;

int n, m, a[52][52], result = 999999999;
vector<pair<int, int>> h, c;
vector<vector<int>> cList;

void combi(int s, vector<int> v){
    if(v.size() == m){
        cList.push_back(v);
        return;
    }
    for(int i = s + 1; i < c.size(); i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) h.push_back({i, j});
            if(a[i][j] == 2) c.push_back({i, j});
        }
    }
    vector<int> v;
    combi(-1, v);
    for(vector<int> list : cList){
        int ret = 0;
        for(pair<int,int> _h : h){
            int minNum = 999999999;
            for(int listNum : list){
                int distance = abs(_h.first - c[listNum].first) + abs(_h.second - c[listNum].second);
                minNum = min(minNum, distance);
            }
            ret += minNum;
        }
        result = min(result, ret);
    }
    cout << result << '\n';
    return 0;
}