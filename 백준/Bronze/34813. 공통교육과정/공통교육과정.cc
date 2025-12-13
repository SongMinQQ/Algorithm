#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    char t = s[0];

    if (t == 'F') cout << "Foundation";
    else if (t == 'C') cout << "Claves";
    else if (t == 'V') cout << "Veritas";
    else if (t == 'E') cout << "Exploration";

    return 0;
}
