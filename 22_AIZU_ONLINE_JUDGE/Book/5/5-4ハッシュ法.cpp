#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

const int M = 1046527;
const int NIL = -1;

vector<ll> H(M,NIL);

// ハッシュ法を実装する
ll h1(ll key){ return key % M; }

ll h2(ll key){ return 1 + (key % (M-1)); }

// 文字列から数値に変換
int getChar(char ch){
    if(ch == 'A') return 1;
    else if(ch == 'C') return 2;
    else if(ch == 'G') return 3;
    else if(ch == 'T') return 4;
    else return 0;
}

// 文字列から数値を変換してKeyを生成する
ll getKey(string S){
    ll sum = 0;
    rep(i,S.size()){
        char ch = S[i];
        sum += getChar(ch) * pow(10,S.size()-i+1);
    }
    return sum;
}

bool find(string S){
    ll key;
    key = getKey(S);
    int i=0;
    while(true){
        int H_ind = h1(key) + i*h2(key);
        if(H[H_ind] == NIL){
            return true;
        }
        i++;
    }
}



int main()
{
    
}