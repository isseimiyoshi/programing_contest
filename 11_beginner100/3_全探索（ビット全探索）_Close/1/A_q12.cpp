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

const int MAX_N = 12;

int main()
{
    int N, M; cin >> N >> M;
    vector<pair<int, int> > A(M);
    rep(i,M){
        cin >> A[i].first >> A[i].second;
        A[i].first--; A[i].second--;
    }
    int max_com = 0;
    for(int tmp=0; tmp<(1<<N); tmp++){
        bitset<MAX_N> bit(tmp);
        int com = 0;
        rep(i,N){
            if(bit.test(i)) com++;
        }
        int required = (com-1)*com/2;
        rep(i,M){
            if(bit.test(A[i].first) && bit.test(A[i].second)) required--;
        }
        if(required == 0) if(max_com < com) max_com = com;
    }
    cout << max_com << endl;
}