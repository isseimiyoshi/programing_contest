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

const int MIN = -1000100100; 

int main()
{
    int D, N; cin >> D >> N;
    int T[D];
    rep(i,D) cin >> T[i];
    vector<tuple<int, int, int> > ABC;
    rep(i,N){
        int A, B, C; cin >> A >> B >> C;
        ABC.push_back(make_tuple(A, B, C));
    }

    // 動的計画法を適用するための二次元ベクトルを設定
    int f[D][N];
    // 初期化
    rep(i,D) rep(j,N) f[i][j] = MIN;

    rep(i,D){
        rep(j,N){
            int Aj, Bj, Cj;
            tie(Aj, Bj, Cj) = ABC[j];
            if(Aj<=T[i] && T[i]<=Bj){
                if(i == 0){
                    f[i][j] = 0;
                    continue;
                }
                rep(k,N){
                    int Ak, Bk, Ck;
                    tie(Ak, Bk, Ck) = ABC[k];
                    f[i][j] = max(f[i][j], f[i-1][k]+abs(Cj-Ck));
                }
            }else{
                f[i][j] = MIN;
            }
            // cout << f[i][j] << " ";
        }
        // cout << endl;
    }
    int maxs = MIN;
    rep(i,N){
        maxs = max(maxs, f[D-1][i]);
    }
    cout << maxs << endl;
}