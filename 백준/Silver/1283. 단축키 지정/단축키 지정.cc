#include <bits/stdc++.h>
using namespace std;

bool used[26];

bool optionCheck(char c) {
    c = toupper(c);
    int idx = c - 'A';
    if (used[idx]) {
        return false;
    }
    used[idx] = true;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> result;
    result.reserve(n);

    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        {
            string w;
            while(ss >> w) {
                words.push_back(w);
            }
        }

        bool shortcutAssigned = false;
        int shortcutWordIndex = -1;
        int shortcutCharIndex = -1;

        for(int wi = 0; wi < (int)words.size(); wi++){
            if (!words[wi].empty()) {
                if(optionCheck(words[wi][0])) {
                    shortcutAssigned = true;
                    shortcutWordIndex = wi;
                    shortcutCharIndex = 0;
                    break;
                }
            }
        }

        if(!shortcutAssigned) {
            for(int wi = 0; wi < (int)words.size(); wi++){
                for(int ci = 1; ci < (int)words[wi].size(); ci++){
                    if(optionCheck(words[wi][ci])) {
                        shortcutAssigned = true;
                        shortcutWordIndex = wi;
                        shortcutCharIndex = ci;
                        break;
                    }
                }
                if(shortcutAssigned) break;
            }
        }

        if(shortcutAssigned) {
            string &targetWord = words[shortcutWordIndex];
            int ci = shortcutCharIndex;
            targetWord = 
                targetWord.substr(0, ci) 
                + "[" + targetWord[ci] + "]" 
                + targetWord.substr(ci + 1);
        }

        ostringstream oss;
        for(int wi = 0; wi < (int)words.size(); wi++){
            if(wi > 0) oss << ' ';
            oss << words[wi];
        }
        result.push_back(oss.str());
    }

    for(const auto &r : result){
        cout << r << "\n";
    }

    return 0;
}
