#include <bits/stdc++.h>
using namespace std;

int addressArr[1002][4];
int n;

bool allSameByte(int i) {
    int refVal = addressArr[0][i];
    for(int r = 1; r < n; r++){
        if(addressArr[r][i] != refVal)
            return false;
    }
    return true;
}

int commonBitsInByte(int i) {
    int mn = 255, mx = 0;
    for(int r = 0; r < n; r++){
        int val = addressArr[r][i];
        mn = min(mn, val);
        mx = max(mx, val);
    }
    int diff = mn ^ mx;

    if(diff == 0) {
        return 8;
    }

    int commonCount = 0;
    for(int shiftCount = 0; shiftCount < 8; shiftCount++){
        if((diff & 0x80) != 0) {
            break;
        } else {
            commonCount++;
            diff <<= 1; 
        }
    }
    return commonCount;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        string ip; 
        cin >> ip;
        {
            istringstream iss(ip);
            for(int j = 0; j < 4; j++){
                string part;
                getline(iss, part, '.');
                addressArr[i][j] = stoi(part);
            }
        }
    }

    if(n == 1){
        cout << addressArr[0][0] << "." << addressArr[0][1] << "." 
             << addressArr[0][2] << "." << addressArr[0][3] << "\n";
        cout << "255.255.255.255\n";
        return 0;
    }

    int mask[4] = {0,0,0,0};
    int netAddr[4] = {0,0,0,0};

    int differIndex = -1;
    for(int i=0; i<4; i++){
        if(allSameByte(i)) {
            mask[i] = 255;
            netAddr[i] = addressArr[0][i];
        } else {
            differIndex = i;
            int cBits = commonBitsInByte(i);

            int bitmask = 0; 
            for(int b=0; b<cBits; b++){
                bitmask |= (1 << (7 - b)); 
            }
            mask[i] = bitmask & 0xFF; 
            netAddr[i] = addressArr[0][i] & mask[i];
            for(int k = i+1; k < 4; k++){
                mask[k] = 0;
                netAddr[k] = 0;
            }
            break;
        }
    }
    cout << netAddr[0] << "." << netAddr[1] << "." << netAddr[2] << "." << netAddr[3] << "\n";
    cout << mask[0] << "." << mask[1] << "." << mask[2] << "." << mask[3] << "\n";

    return 0;
}
