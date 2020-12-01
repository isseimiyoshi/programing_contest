#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    while(true){
        int n, x;
        cin >> n >> x;
        if(n == 0 && x == 0) break;
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i<j && j<k){
                        if(i+j+k+3 == x) count += 1;
                    }
                }
            }
        }
        cout << count << endl;
    }
}