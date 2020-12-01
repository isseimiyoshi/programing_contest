#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector <int> t_i(N);
    vector <int> x_i(N);
    vector <int> y_i(N);
    for(int i=0; i<N; i++){
        cin >> t_i[i] >> x_i[i] >> y_i[i];
    }
    // AtCoDeer君が位置する座標
    int x = 0;
    int y = 0;
    int isYes = 1;
    int ori_ti; // 一つ前のt_iを格納する変数
    for(int i=0; i<N; i++){
        if(i == 0){
            ori_ti = 0;
        }else{
            ori_ti = t_i[i-1];
        }
        // t_iの回数だけ回る
        for(int j=0; j<(t_i[i]-ori_ti); j++){
            if(abs(x-x_i[i]) >= abs(y-y_i[i])){
                if((x_i[i]-x) >= 0){
                    x += 1;
                }else{
                    x -= 1;
                }
            }else{
                if((y_i[i]-y) >= 0){
                    y += 1;
                }else{
                    y -= 1;
                }
            }
            // cout << x << "," << y << endl;
        }
        if((x == x_i[i]) && (y == y_i[i])){
            // cout << "yes" << endl;
            continue;
        }else{
            // cout << "no" << endl;
            isYes = 0;
            break;
        }
    }
    if(isYes == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}