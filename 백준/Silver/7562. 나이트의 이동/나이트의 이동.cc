#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1,2,2,1,-1,-2,-2,-1};
const int dy[] = {2,1,-1,-2,-2,-1,1,2};

int a[302][302], visited[302][302], num1, num2, i, curx, cury, movx, movy, n, y, x;

void bfs(int ay, int ax){
    queue<pair<int, int>> q;
    visited[ay][ax] = 1;
    q.push({ay, ax});
    while(!q.empty()){
        tie(y, x) = q.front();
        q.pop();
        for(int j = 0; j < 8; j++){
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(ny < 0 || nx < 0 || ny >= i || nx >= i || visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
}
int main(){
    cin >> n;

    for(int j = 0; j < n; j++){
        cin >> i >> cury >> curx >> movy >> movx;
        bfs(cury, curx);
        cout << visited[movy][movx] - 1 << '\n';
        fill(&visited[0][0], &visited[301][301], 0);
        fill(&a[0][0], &a[301][301], 0);
    }
    return 0;
}
