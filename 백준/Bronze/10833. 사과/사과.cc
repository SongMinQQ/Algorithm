#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    int students, apples;
    int leftover_sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> students >> apples;
        leftover_sum += apples % students;
    }

    cout << leftover_sum << '\n';
    return 0;
}
