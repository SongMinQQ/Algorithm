#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char a[21][21];
int r, c, result = 0, check;

void dfs(int y, int x, int num, int cnt){
    result = max(result, cnt);
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        int nextNum = (1 << (int)(a[ny][nx] - 'A'));
        if((num & nextNum) == 0) {
            dfs(ny, nx, (num | nextNum), cnt + 1);
        }
    }
}
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        string line;
        cin >> line;
        for(int j = 0; j < line.size(); j++){
            a[i][j] = line[j];
        }
    }
    dfs(0, 0, (1 << (int)a[0][0] - 'A'), 1);
    cout << result << '\n';
}