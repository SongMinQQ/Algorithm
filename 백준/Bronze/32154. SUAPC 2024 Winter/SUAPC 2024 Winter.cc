#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<string>> solved = {
        {},
        {"A","B","C","D","E","F","G","H","J","L","M"}, // 1등
        {"A","C","E","F","G","H","I","L","M"},          // 2등
        {"A","C","E","F","G","H","I","L","M"},          // 3등
        {"A","B","C","E","F","G","H","L","M"},          // 4등
        {"A","C","E","F","G","H","L","M"},          // 5등
        {"A","C","E","F","G","H","L","M"},          // 6등
        {"A","C","E","F","G","H","L","M"},          // 7등
        {"A","C","E","F","G","H","L","M"},          // 8등
        {"A","C","E","F","G","H","L","M"},          // 9등
        {"A","B","C","F","G","H","L","M"}           // 10등
    };

    cout << solved[N].size() << "\n";
    for (int i = 0; i < (int)solved[N].size(); i++) {
        if (i) cout << ' ';
        cout << solved[N][i];
    }
    cout << "\n";
    return 0;
}
