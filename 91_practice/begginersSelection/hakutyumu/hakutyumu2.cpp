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
    int strLen;
    strLen = S.size();
    cout << S.substr(strLen-3, 3) << endl;
    cout << S.substr(0, strLen-3) << endl;
}