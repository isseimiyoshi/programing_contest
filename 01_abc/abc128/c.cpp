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
    int N, M; cin >> N >> M;
    vector<int> L[M];
    rep(i,M){
        int ki; cin >> ki;
        rep(j,ki){
            int s; cin >> s;
            //cout << s << endl;
            L[i].push_back(s-1);
        }
    }
    int P[M];
    rep(i,M){
        int p; cin >> p;
        P[i] = p;
    }

    

    int sum = 0;
    for(int i=0; i<pow(2,N); i++){
        bitset<10> B(i);
        int On_num = 0;
        rep(j,M){
            int Lj_sum = 0;
            rep(k,L[j].size()){
                if(B.test(L[j][k])) Lj_sum++;
            }
            if(P[j] == (Lj_sum%2)) On_num++;
        }
        if(On_num == M){
            sum++;
            // cout << B << endl;
        }
    }
    cout << sum << endl;
}