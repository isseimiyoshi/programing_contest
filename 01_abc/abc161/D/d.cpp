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
    int64_t K;
    cin >> K;
    int64_t lunlun_num = 0;
    int64_t lun;
    for(int64_t i=1; i<1000000000000000; i++){
        // cout << i << endl;
        bool judge = lunlun(i);
        if(judge){
            lunlun_num += 1;
        }
        if(lunlun_num == K){
            lun = i;
            break;
        }
    }   
    cout << lun << endl;
}