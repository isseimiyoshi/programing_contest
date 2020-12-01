#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int sen, hyaku, zyu, iti;
    // 千の位
    sen = N / 1000;
    N -= 1000*sen;
    // 百の位
    hyaku = N / 100;
    N -= 100*hyaku;
    // 十の位
    zyu = N / 10;
    N -= 10*zyu;
    // 一の位
    iti = N;
    bool isGood = false;
    if((sen == hyaku) && (hyaku == zyu) && (zyu == iti)){
        isGood = true;
    }else if((sen == hyaku) && (hyaku == zyu)){
        isGood = true;
    }else if((hyaku == zyu) && (zyu == iti)){
        isGood = true;
    }
    if(isGood) cout << "Yes" << endl;
    else cout << "No" << endl;
}