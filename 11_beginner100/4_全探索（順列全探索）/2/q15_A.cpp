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
    vector<P> c(n);
    vector<int> v(n);
    rep(i,n){
        int x, y; cin >> x >> y;
        c[i] = make_pair(x, y);
        v[i] = i;
    }

    double ans = 0;
    int cnt = 0;
    do{ 
        double sum = 0;
        rep(i,n-1){
            int x1 = c[v[i]].first, y1 = c[v[i]].second;
            int x2 = c[v[i+1]].first, y2 = c[v[i+1]].second;
            sum += sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        }
        ans += sum;
        cnt++;
    }while(next_permutation(v.begin(), v.end()));

    printf("%.6f\n", ans/cnt);
}