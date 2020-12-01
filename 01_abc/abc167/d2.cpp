#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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
    ll N, K; cin >> N >> K;
    vector<pair<ll, ll> > C(N);
    vector<ll> A(N);
    // 初期化
    rep(i,N){
        C[i] = make_pair(0, 0);
        cin >> A[i]; A[i]--;
    }
    ll count = -1, next = 0;
    ll roop, start, cnt0;
    rep(_,2*N){
        C[next].first++;
        count++;
        if(C[next].first == 2){
            roop = count - C[next].second;
            start = next;
            cnt0 = C[next].second;
            break;
        }
        C[next].second = count;
        next = A[next];
    }
    if(K < cnt0){
        next = 0;
        rep(_,K){
            next = A[next];
        }
        next++;
        cout << next << endl;
    }
    else{
        K = K - cnt0;
        K = K % roop;
        next = start;
        rep(_,K){
            next = A[next];
        }
        next++;
        cout << next << endl;
    }
}