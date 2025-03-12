#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int left = 0, right = n - 1;
        int minDiff = INT_MAX;
        long long count = 0;
        while(left < right){
            int sum = v[left] + v[right];
            int diff = abs(sum - k);
            
            if(diff < minDiff){
                minDiff = diff;
                count = 1;
            }
            else if(diff == minDiff){
                count++;
            }
            if(sum > k)
                right--;
            else
                left++;
        }
        
        cout << count << "\n";
    }
    
    return 0;
}
