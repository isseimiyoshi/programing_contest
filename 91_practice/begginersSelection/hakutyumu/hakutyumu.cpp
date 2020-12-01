#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    // 使用する各文字列を変数に格納する
    string dream = "dream";
    string dreamer = "dreamer";
    string erase = "erase";
    string eraser = "eraser";
    int isMatch = 0;
    int strLen;
    while(true){
        strLen = S.size();
        if(strLen <= 7){
            if((S == dream) || (S == dreamer) || (S == erase) || (S == eraser)){
                isMatch = 1;
                break;
            }
            break;
        }
        if(S.substr(strLen-5,5) == erase){
            S = S.substr(0, strLen-5);
            if(S.empty()){
                isMatch = 1;
                break;
            }
        }else if(S.substr(strLen-5,5) == dream){
            S = S.substr(0, strLen-5);
            if(S.empty()){
                isMatch = 1;
                break;
            }
        }else if(S.substr(strLen-6,6) == eraser){
            S = S.substr(0, strLen-6);
            if(S.empty()){
                isMatch = 1;
                break;
            }
        }else if(S.substr(strLen-7,7) == dreamer){
            S = S.substr(0, strLen-7);
            if(S.empty()){
                isMatch = 1;
                break;
            }
        }else{
            break;
        }
    }
    if(isMatch == 0){
        cout << "NO" << endl;
    }else if(isMatch == 1){
        cout << "YES" << endl;
    }
}
