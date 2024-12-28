#include <bits/stdc++.h>
using namespace std;

const int MAX = 500002;
int n, k, visited[2][MAX + 10], speed = 1;
bool isVisit;
void bfs(int n){
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        k += speed;
        if(k > MAX - 2) break;
        if(visited[speed % 2][k]){
            isVisit = true;
            break;
        }
        // +1, -1, *2 방향으로 BFS 탐색
        int qSize = q.size();
        for(int j = 0; j < qSize; j++){
            int now = q.front();
            q.pop();
            for(int i : {now * 2, now - 1, now + 1 }){
                if(0 > i || i > MAX - 2 || visited[speed % 2][i]) continue;
                visited[speed % 2][i] = visited[(speed + 1) % 2][now] + 1;
                if(i == k){
                    isVisit = true; break;
                }
                q.push(i);
            }
            if(isVisit) break;
        }
        if(isVisit) break;
        speed++;
    }
}
int main(){
    // fill(visited, visited + MAX, -1);
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }
    if(n >= 500000) {cout << -1 << '\n'; return 0;}
    visited[0][n] = 1;
    bfs(n);
    if(isVisit) cout << speed << '\n';
    else cout << -1 << '\n';
    return 0;
}