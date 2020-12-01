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
    int N; cin >> N;
    vector<pair<ll, ll> > P(N);
    rep(i,N){
        ll A, B; cin >> A >> B;
        P[i] = make_pair(B, A);
    }
    sort(P.begin(), P.end());
    // rep(i,P.size()) cout << P[i].first << " " << P[i].second << endl;
    ll sum = 0; bool isComp = true;
    rep(i,P.size()){
        sum += P[i].second;
        if(sum > P[i].first){
            isComp = false;
            break;
        }
    }
    if(isComp) cout << "Yes" << endl;
    else cout << "No" << endl;
}