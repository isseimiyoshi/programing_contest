#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    while(true){
        int H, W;
        cin >> H >> W;
        if(H == 0 && W == 0) break;
        for(int i=0; i<H; i++){
            if(i == 0 || i == H-1){
                for(int j=0; j<W; j++) cout << '#';
            }else{
                cout << '#';
                for(int j=1; j<W-1; j++){
                    cout << '.';
                }
                cout << '#';
            }
            cout << endl;
        }
        cout << endl;
    }
}