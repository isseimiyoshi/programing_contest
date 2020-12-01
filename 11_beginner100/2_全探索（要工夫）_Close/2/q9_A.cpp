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
    int m; cin >> m;
    vector<P> t(m);
    rep(i,m){
        int tx, ty; cin >> tx >> ty;
        t[i] = make_pair(tx, ty);
    }

    int n; cin >> n;
    vector<P> xy(n);
    rep(i,n){
        int x, y; cin >> x >> y;
        xy[i] = make_pair(x, y);
    }

    sort(xy.begin(), xy.end());

    int difx, dify;
    rep(i,n){
        rep(j,m){
            int cnt = 0;
            rep(k,m){
                if(k == j) continue;

                int x2 = xy[i].first + t[k].first - t[j].first;
                int y2 = xy[i].second + t[k].second - t[j].second;

                if(lower_bound(xy.begin(), xy.end(), make_pair(x2, y2)) != upper_bound(xy.begin(), xy.end(), make_pair(x2, y2))){
                    cnt++;
                }
            }
            if(cnt == m-1){
                difx = xy[i].first - t[j].first;
                dify = xy[i].second - t[j].second;
                break;
            }
        }
    }

    printf("%d %d\n", difx, dify);

    return 0;
}