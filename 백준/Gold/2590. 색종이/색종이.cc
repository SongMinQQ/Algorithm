#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int paper;
int main(){
    int count = 0;
    for(int i = 1; i < 7; i++){
        cin >> paper;
        v.push_back(paper);
    }
    if(v[5] != 0) count+=v[5];
    if(v[4] != 0){
        while(v[4] > 0){
            int area = 36;
            v[4]--;
            area -= 25;
            if (v[0] <= area)
                v[0] = 0;
            else
                v[0] -= area;
            count++;
        }
    }
    if(v[3] != 0){
        while (v[3]>0)
        {
            int area = 36;
            v[3]--;
            area -= 16;
            if (v[1]>5){
                v[1] -= 5;
                area -= 20;
            }
            else{
                area -= 4 * v[1];
                v[1] = 0;
            }
            if (v[0] <= area)
                v[0] = 0;
            else
                v[0] -= area;
            count++;
        }
    }
    if(v[2] != 0){
        while(v[2] > 0){
            int area = 36;
            if (v[2]>4){
                v[2] -= 4;
                area = 0;
            }
            else{
                area -= 9 * v[2];
                v[2] = 0;
            }
            if (area == 27 && v[1]>5)
            {
                v[1] -= 5;
                area -= 20;
            }
            else if (area == 27 && v[1] <= 5)
            {
                area -= 4 * v[1];
                v[1] = 0;
            }
            if (area == 18 && v[1]>3)
            {
                v[1] -= 3;
                area -= 12;
            }
            else if (area == 18 && v[1] <= 3)
            {
                area -= 4 * v[1];
                v[1] = 0;
            }
            if (area == 9 && v[1] >= 1)
            {
                area -= 4 * v[1];
                v[1] = 0;
            }
            if (v[0] <= area)
                v[0] = 0;
            else
                v[0] -= area;
            count++;
        }
    }
    if(v[1] != 0){
        while(v[1] > 0){
            int area = 36;
            if(v[1] > 9) {v[1] -= 9; area = 0;}
            else { 
                area -= 4 * v[1]; 
                v[1] = 0;
            }
            if (v[0] <= area)
                v[0] = 0;
            else
                v[0] -= area;
            count++;
        }
    }
    if(v[0] != 0){
        while(v[0] > 0){
            if(v[0] > 36) v[0] -= 36;
            else v[0] = 0;
            count++;
        }
    }
    cout << count;
}