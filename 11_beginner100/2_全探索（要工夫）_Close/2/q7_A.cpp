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
    int n; cin >> n;
    vector<P> p;
    rep(i,n){
        int x, y; cin >> x >> y;
        p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end());

    int ans = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            int x1, y1, x2, y2;
            x1 = p[i].first; y1 = p[i].second;
            x2 = p[j].first; y2 = p[j].second;

            int x3 = x2 + (y1-y2);
            int y3 = y2 + (x2-x1);
            int x4 = x1 + (y1-y2);
            int y4 = y1 + (x2-x1);

            if(lower_bound(p.begin(), p.end(), make_pair(x3, y3)) != upper_bound(p.begin(), p.end(), make_pair(x3, y3))){
                if(lower_bound(p.begin(), p.end(), make_pair(x4, y4)) != upper_bound(p.begin(), p.end(), make_pair(x4, y4))){
                    ans = max(ans, (x2-x1)*(x2-x1)+(y1-y2)*(y1-y2));
                }
            }
        }
    }
    cout << ans << endl;

}