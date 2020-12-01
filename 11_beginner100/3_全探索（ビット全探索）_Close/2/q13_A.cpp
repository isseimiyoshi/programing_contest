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

const int MAX_R = 10;

int main()
{
    int r, c; cin >> r >> c;
    int o[r][c];
    rep(i,r) rep(j,c) cin >> o[i][j];

    int ans = -1;
    // 行を裏返すやり方で全探索する
    rep(i,(1<<r)){
        bitset<MAX_R> b(i);

        int sum = 0;

        rep(k,c){
            int cnt1 = 0;
            rep(j,r){
                if(b.test(j) && o[j][k] == 0) cnt1++;
                else if(!b.test(j) && o[j][k]) cnt1++;
            }
            if(cnt1 > r/2) sum += cnt1;
            else sum += (r-cnt1);
        }

        /*
        rep(j,r){
            int cnt1 = 0;
            rep(k,c){
                if(b.test(j) && o[j][k] == 0) cnt1++;
                else if(!b.test(j) && o[j][k]) cnt1++;
            }
            if(cnt1 > c/2) sum += cnt1;
            else sum += (c-cnt1);
        }
        */

        ans = max(ans, sum);
    }
    cout << ans << endl;
}