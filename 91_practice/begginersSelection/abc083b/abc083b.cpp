#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int count = 0;    // 条件に合う数字の合計を格納する変数
    
    for(int i=1; i<=N; i++){
        int ori_i = i;
        // cout << i << endl;
        int man = 0;
        if(i >= 10000){
            man = i / 10000;
            i -= man*10000;
        }
        int sen = 0;
        if(i >= 1000){
            sen = i / 1000;
            i -= sen*1000;
        }
        int hyaku = 0;
        if(i >= 100){
            hyaku = i / 100;
            i -= hyaku*100;
        }
        int zyu = 0;
        if(i>=10){
            zyu = i / 10;
            i -= zyu*10;
        }
        int iti = i;
        int sum = man + sen + hyaku + zyu + iti;
        if(A <= sum){
            if(sum <= B){
                count += ori_i;
            }
        }
    }

    cout << count << endl;
}