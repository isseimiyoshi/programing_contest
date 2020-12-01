#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool lunlun(int64_t num){
    if(num < 10){
        return true;
    }
    string s_num = to_string(num);
    int64_t keta = s_num.size();
    //out << keta << endl;
    int64_t lunlun_count = 0;
    for(int64_t j=0; j<(keta-1); j++){
        if(num < 10) break;
        int64_t zyu = (num % 100) / 10;
        int64_t iti = num % 10;
        if(abs(zyu - iti) <= 1){
            lunlun_count += 1;
            num = num / 10;
        }else{
            return false;
        }
    }
    if(lunlun_count == (keta - 1)) return true;
    else return false;
}

int main()
{
    int K;
    cin >> K;
    int64_t lunlun_num;
    int lunlun_count;
    for(int64_t i=1; i<10000000000000000; i++){
        if(i < 10){
            lunlun_count += 1;
            continue;
        }
        string s_num = to_string(i);
        int keta = s_num.size();
        int max_keta = i / pow(10, keta-1);
        int max_1_keta = (i - (max_keta*pow(10, keta - 1))) / pow(10, keta - 2);
        if(abs(max_keta - max_1_keta) > 1){
            if(max_keta == 1){
                i = (max_keta + 1) * pow(10, keta-1);
            }else{
                if((max_keta - max_1_keta) >= 2){
                    i = (max_keta + 1) * pow(10, keta-1);
                }
            }
        }
        bool judge = lunlun(i);
        if(judge){
            lunlun_count += 1;
            // cout << lunlun_count << endl;
            //cout << i << endl;
        }
        if(lunlun_count == K){
            lunlun_num = i;
            break;
        }
    }
    cout << lunlun_num << endl;
}