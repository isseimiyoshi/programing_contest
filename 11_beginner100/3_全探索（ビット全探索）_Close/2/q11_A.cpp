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

const int MAX_N = 11;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> s[m];
    vector<int> k(m);
    rep(i,m){
        cin >> k[i];
        rep(_,k[i]){
            int sij; cin >> sij; sij--;
            s[i].push_back(sij);
        }
    }
    vector<int> p(m);
    rep(i,m) cin >> p[i];

    int ans = 0;
    rep(i,(1<<n)){
        bitset<MAX_N> b(i);

        int sum = 0;
        rep(j,m){
            int on = 0;
            rep(kk, k[j]){
                if(b.test(s[j][kk])){
                    on++;
                }
            }
            if(on%2 == p[j]) sum++;
        }
        if(sum == m) ans++;
    }

    cout << ans << endl;

    return 0;
}