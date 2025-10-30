#include<bits/stdc++.h>
using namespace std;

int n, cal[4], minRet = INT_MAX, maxRet = INT_MIN;
vector<int> v;
void go(int cur, int dep){
    if(dep == n - 1){
        minRet = min(minRet, cur);
        maxRet = max(maxRet, cur);
        return;
    }
    for (int j = 0; j < 4; j++){
        int next = cur;
        if(cal[j] == 0) continue;
        if(j == 0) next = cur + v[dep + 1];
        else if(j == 1) next = cur - v[dep + 1];
        else if(j == 2) next = cur * v[dep + 1];
        else next = cur / v[dep + 1];
        cal[j]--;
        go(next, dep + 1);
        cal[j]++;
    }
    return;
}
int main(){
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int i = 0; i < 4; i++){
        cin >> cal[i];
    }
    go(v[0], 0);
    cout << maxRet << '\n' << minRet;
    return 0;
}