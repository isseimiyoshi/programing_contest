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

int main()
{
    int N,M; cin >> N >> M;
    priority_queue<int> A;
    rep(i,N){
        int Ai; cin >> Ai;
        A.push((-1)*Ai);
    }
    rep(i,M){
        int B, C; cin >> B >> C;
        rep(j,B){
            if(A.top() > (-1)*C){
                A.pop(); A.push((-1)*C);
            }else{
                break;
            }
        }
    }
    ll sum = 0;
    rep(i,N){
        sum += A.top(); A.pop();
    }
    cout << (-1)*sum << endl;
}