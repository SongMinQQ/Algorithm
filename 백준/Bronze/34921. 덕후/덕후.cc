#include<iostream>
using namespace std;
int a, t, p;
int main(){
    cin >> a >> t;
    p = 10+2*(25-a+t);
    p > 0 ? cout << p : cout << 0;
    return 0;
}