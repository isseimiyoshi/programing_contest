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

int c[10][1005];

const int INF = 1000100100;

int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    int ans = INF;

    rep(div,1<<(h-1)){  // div: 横方向に切る線の書き方の集合
        // 横方向の区切り線によるグルーピング
        int g = 0;
        vector<int> id(h);
        rep(i,h){
            id[i] = g;
            if(div>>i&1) ++g;
        }
        ++g;    // gはグループ数を表すようにしたいので、最後にインクリメント

        rep(i,g) rep(j,w) c[i][j] = 0;
        rep(i,h) rep(j,w) c[id[i]][j] += (s[i][j] - '0');

        int num = g-1;
        vector<int> now(g); // これを定義した時点で次元gのベクトルnowは初期化される
        auto add = [&](int j){
            rep(i,g) now[i] += c[i][j];
            rep(i,g) if(now[i] > k) return false;
            return true;
        };
        rep(j,w){
            if(!add(j)){
                num++;
                now = vector<int> (g);  // これでベクトルnowがすべて0に初期化される
                if(!add(j)){
                    num = INF;
                    break;
                }
            }
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
}