#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A'; 

int main()
{
    int n; cin >> n;
    int taro = 0, hanako = 0;
    for(int i=0; i<n; i++){
        string taro_s, hanako_s; cin >> taro_s >> hanako_s;
        if(taro_s == hanako_s){
            taro += 1;
            hanako += 1;
        }else if(taro_s > hanako_s){
            taro += 3;
        }else{
            hanako += 3;
        }
    }
    printf("%d %d\n", taro, hanako);
}