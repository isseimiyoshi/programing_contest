#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

const int MAX_R = 100100;

int main()
{  
    bool isprime[MAX_R];
    rep(i,MAX_R) isprime[i] = true;

    isprime[0] = isprime[1] = false;
    for(int i=2; i<MAX_R; i++){
        int j = i+i;
        while(j<MAX_R){
            isprime[j] = false;
            j += i;
        }
    }

    int sim2017[MAX_R];
    sim2017[0] = sim2017[1] = sim2017[2] = 0;
    for(int i=3; i<MAX_R; i++){
        if(i%2 == 0) sim2017[i] = sim2017[i-1];
        else{
            if(isprime[i] && isprime[(i+1)/2]){
                sim2017[i] = sim2017[i-1]+1;
            }else{
                sim2017[i] = sim2017[i-1];
            }
        }
    }

    int q; cin >> q;
    rep(_,q){
        int l,r; cin >> l >> r;
        cout << (sim2017[r]-sim2017[l-1]) << endl;
    }
}