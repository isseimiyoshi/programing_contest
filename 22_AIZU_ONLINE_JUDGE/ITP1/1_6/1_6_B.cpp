#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int S[13], H[13], C[13], D[13];
    for(int i=0; i<13; i++){
        S[i] = i+1;
        H[i] = i+1;
        C[i] = i+1;
        D[i] = i+1;
    }
    int n;
    cin >> n;
    char mark; int num;
    for(int i=0; i<n; i++){
        cin >> mark >> num;
        if(mark == 'S') S[num-1] = -1;
        else if(mark == 'H') H[num-1] = -1;
        else if(mark == 'C') C[num-1] = -1;
        else if(mark == 'D') D[num-1] = -1;
    }
    for(int i=0; i<4; i++){
        if(i == 0){
            for(int j=0; j<13; j++){
                if(S[j] == j+1) cout << "S " << j+1 << endl;
            }
        }else if(i == 1){
            for(int j=0; j<13; j++){
                if(H[j] == j+1) cout << "H " << j+1 << endl;
            }
        }else if(i == 2){
            for(int j=0; j<13; j++){
                if(C[j] == j+1) cout << "C " << j+1 << endl;
            }
        }else if(i == 3){
            for(int j=0; j<13; j++){
                if(D[j] == j+1) cout << "D " << j+1 << endl;
            }
        }
    }
}