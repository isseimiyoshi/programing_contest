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
    int H, W, K; cin >> H >> W >> K;
    vector<vector<int>> M(H, vector<int>(W));
    int sum = 0;
    rep(i,H){
        rep(j,W){
            char m; cin >> m;
            if(m == '.'){
                M[i][j] = 0;
            }else{
                M[i][j] = 1;
                sum++;
            }
        }
    }

    vector<int> Wnum(W, 0);
    vector<int> Hnum(H, 0);

    rep(j,W){
        rep(i,H){
            Wnum[j]++;
        }
    }
    rep(i,H){
        rep(j,W) Hnum[i]++;
    }
    int pattern = 0;
    // ビット演算で色を塗り替える行列を決定する
    for(int tmp1=0; tmp1<(1<<H); tmp1++){
        for(int tmp2=0; tmp2<(1<<W); tmp2++){
            bitset<6> hbit(tmp1);
            bitset<6> wbit(tmp2);
            vector<vector<int>> M2(H, vector<int>(W));
            M2 = M;
            rep(i,W){
                if(wbit.test(i)) rep(j,H) M2[j][i] = 2;
            }
            rep(i,H){
                if(hbit.test(i)) rep(j,W) M2[i][j] = 2;
            }
            int cnt = 0;
            rep(i,H){
                rep(j,W) if(M2[i][j] == 1) cnt++;
            }
            if(cnt == K) pattern++;
        }
    }
    cout << pattern << endl;
}