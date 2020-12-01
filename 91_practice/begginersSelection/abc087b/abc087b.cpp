#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num500, num100, num50, sum;
    cin >> num500 >> num100 >> num50 >> sum;
    int count = 0;
    for(int i=num500; i>=0; i--){
        if(500*i > sum){
            continue;
        }else if(500*i < sum){
            // 500円硬貨の合計が提示合計金額を下回った場合
            for(int j=num100; j>=0; j--){
                if(100*j > sum-500*i){
                    continue;
                }else if(100*j < sum-500*i){
                    for(int k=num50; k>=0; k--){
                        if(50*k > sum-500*i-100*j){
                            continue;
                        }else if(50*k < sum-500*i-100*j){
                            continue;
                        }else{
                            count += 1;
                        }
                    }
                }else{
                    count += 1;
                }
            }
        }else{
            // 500円硬貨の合計が提示金額丁度だった場合
            count += 1;
        }
    }
    cout << count << endl;
}