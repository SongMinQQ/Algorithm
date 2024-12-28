#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[51][51];
int n, m, visited[51][51], maxNum = 0, y, x;

void bfs(int s1, int s2){
    queue<pair<int, int>> q;
    q.push({s1, s2});
    while(q.size()){
        tie(y, x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 'W') continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            maxNum = visited[ny][nx] > maxNum ? visited[ny][nx] : maxNum;
            q.push({ny, nx});
        }
    }
}
int main(){
    fill(&visited[0][0], &visited[50][51], 0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L' && visited[i][j] == 0){
                visited[i][j] = 1;
                bfs(i, j);
                fill(&visited[0][0], &visited[50][51], 0);
            }
        }
    }
    cout << maxNum - 1 << '\n';
    return 0;
}