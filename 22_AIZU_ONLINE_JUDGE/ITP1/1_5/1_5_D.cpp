#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    cin >> n;
    int ori_i;
    for(int i=1; i<=n; i++){
        if(i%3 == 0){
            cout << " " << i;
        }else{
            ori_i = i;
            while(true){
                if(ori_i % 10 == 3){
                    cout << " " << i;
                    break;
                }else{
                    if(ori_i / 10 == 0){
                        break;
                    }else{
                        ori_i /= 10;
                    }
                }
            }
        }
    }
    cout << endl;
}