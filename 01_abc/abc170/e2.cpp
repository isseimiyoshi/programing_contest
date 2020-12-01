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

const int pk_n = 200000;
const int INF = 1000100100;

int main()
{
    int N, Q;   // Nは幼児の人数
    cin >> N >> Q;
    vector<P> pk[pk_n];
    int belong[N];
    int rate[N];
    rep(i,N){
        int Ai, Bi; cin >> Ai >> Bi; --Bi;
        belong[i] = Bi;
        rate[i] = Ai;
        pk[Bi].push_back(make_pair(Ai, i));
    }
    P fair = make_pair(INF, 1);
    rep(i,pk_n){
        sort(pk[i].begin(), pk[i].end(), greater<P>());
        for(P rt: pk[i]){
            if(rt.first == fair.first) ++fair.second;
            else if(rt.first < fair.first){
                fair.first = rt.first;
                fair.second = 1;
            }
            break;
        }
    }
    rep(_,Q){
        int Ci, Di; cin >> Ci >> Di; --Ci, --Di;
        int before_pk = belong[Ci];
        int after_pk = Di;
        belong[Ci] = after_pk;
        
    }
    cout << fair << endl;
}