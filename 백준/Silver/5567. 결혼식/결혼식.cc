#include <bits/stdc++.h>
using namespace std;

vector<int> v[502];
bool visited[502];
int n, m, a, b, cnt = 0;

void bfs(int start) {
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, 0});

    while (!q.empty()) {
        int s = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (depth == 2) continue;

        for (int i : v[s]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push({i, depth + 1});
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    visited[1] = 1;
    bfs(1);
    for(int i = 2; i <= n; i++){
        if(visited[i]) cnt++;
    }
    cout << cnt;
    return 0;
}