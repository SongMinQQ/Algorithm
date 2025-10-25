#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H;
    if (!(cin >> W >> H)) return 0;

    int N; 
    cin >> N;

    vector<int> hCuts = {0, H};
    vector<int> vCuts = {0, W};

    for (int i = 0; i < N; ++i) {
        int dir, pos; 
        cin >> dir >> pos;
        if (dir == 0) hCuts.push_back(pos);
        else          vCuts.push_back(pos);
    }

    sort(hCuts.begin(), hCuts.end());
    sort(vCuts.begin(), vCuts.end());

    int maxH = 0, maxW = 0;
    for (int i = 1; i < (int)hCuts.size(); ++i)
        maxH = max(maxH, hCuts[i] - hCuts[i-1]);
    for (int i = 1; i < (int)vCuts.size(); ++i)
        maxW = max(maxW, vCuts[i] - vCuts[i-1]);

    cout << (maxW * maxH) << '\n';
    return 0;
}
