#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    set<int> sums;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        // 길이가 1부터 n까지의 모든 연속 부분 수열 고려
        for (int j = 0; j < n; j++) {
            sum += elements[(i + j) % n];
            sums.insert(sum);
        }
    }
    
    return sums.size();
}