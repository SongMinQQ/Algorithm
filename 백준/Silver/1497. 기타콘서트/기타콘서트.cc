#include <bits/stdc++.h>
using namespace std;

int n, m;
int bestGuitarsUsed = INT_MAX;
int bestSongCount = 0;
vector<long long> guitarMask; 

void dfs(int idx, int cnt, long long cur) {
    if(idx == n) {
        int songCount = __builtin_popcountll(cur);  // long long용 비트세는 내장함수
        // 최대 연주곡 수와 최소 기타 수 갱신
        if(songCount > bestSongCount) {
            bestSongCount = songCount;
            bestGuitarsUsed = cnt;
        }
        else if(songCount == bestSongCount) {
            bestGuitarsUsed = min(bestGuitarsUsed, cnt);
        }
        return;
    }
    // 기타를 선택하지 않는 경우
    dfs(idx + 1, cnt, cur);
    // 기타를 선택하는 경우
    dfs(idx + 1, cnt + 1, cur | guitarMask[idx]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    guitarMask.resize(n);
    string name, music;
    for (int i = 0; i < n; i++) {
        cin >> name >> music;
        long long mask = 0;
        for (int j = 0; j < m; j++) {
            if(music[j] == 'Y')
                mask |= (1LL << j);  // 1LL 사용!
        }
        guitarMask[i] = mask;
    }
    
    dfs(0, 0, 0LL);
    
    // 한 곡도 연주할 수 없으면 -1, 아니면 최소 기타 수 출력
    cout << (bestSongCount == 0 ? -1 : bestGuitarsUsed);
    return 0;
}
