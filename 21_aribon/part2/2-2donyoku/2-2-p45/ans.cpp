#include<iostream>
#include <bits/stdc++.h>
using namespace std;

/*
input

6
ACDBCB
*/

int main()
{
    int n;
    char S[n];
    cin >> n;
    string str_S;
    cin >> str_S;
    string rev_S = str_S;
    reverse(rev_S.begin(), rev_S.end());
    //cout << rev_S.erase(0,1) << endl;
    for(int i=0; i<n; i++){
        char moji;
        if(str_S.compare(rev_S) <= 0){
            moji = str_S[0];
            str_S.erase(0,1);
            //cout << str_S << endl;
        }else{
            moji = rev_S[0];
            rev_S.erase(0,1);
            //cout << rev_S << endl;
        }
        cout << moji << endl;
        S[i] = moji;
    }
    for(int i=0; i<n; i++) putchar(S[i]);
    putchar('\n');
    // cout << rev_S << endl;
}