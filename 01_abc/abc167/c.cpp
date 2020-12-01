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

const int INF = pow(10,9);
const int MAX_N = 12;

int main()
{
    int N, M, X; cin >> N >> M >> X;
    // bitset<N> S(0);
    vector<int> A[N];
    rep(i,N){
        int c; cin >> c; A[i].push_back(c);
        rep(_,M){
            int Ai; cin >> Ai; A[i].push_back(Ai);
        }
    }
    /*
    rep(i,N){
        rep(j,M+1){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    */
    int mincost = INF;
    for(int i=0; i<pow(2,N); i++){
        int cost = 0;
        bitset<MAX_N> S(i); // 使用する参考書
        int Skill[M];
        rep(j,M) Skill[j] = 0;    // 初期化
        rep(j,N){
            if(S.test(j)){
                cost += A[j][0];
                rep(k,M){
                    Skill[k] += A[j][k+1];
                }
            }
        }
        bool isComp = true;
        rep(j,M){
            if(Skill[j] < X) isComp = false;
        }
        // cout << cost << endl;
        if(isComp){
            if(mincost > cost) mincost = cost;
        }
    }
    if(mincost == INF) cout << -1 << endl;
    else cout << mincost << endl;
}