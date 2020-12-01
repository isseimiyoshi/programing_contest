#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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

const int MAXLN = 100;

ll res = 0;
ll cnt = 0;
vector<int> temp(MAXLN,-1);

ll comp(ll d, ll c){
    if(c == 1) return d;
    if(c % 2 == 1){
        temp[cnt] = d;
        --c, cnt++;
    }
    ll nd = d + d;
    res += c/2;
    if(nd>=10){
        nd = 1+(nd%10);
        res += c/2; 
    }
    return comp(nd, c/2);
}

int main()
{
    ll m; cin >> m;
    ll d[m], c[m];
    rep(i,m) cin >> d[i] >> c[i];

    vector<ll> fin;
    rep(i,m){
        cnt = 0;
        ll com = comp(d[i], c[i]);
        rep(j,cnt){
            com += temp[j];
            res++;
            if(com>=10){
                com = 1 + (com%10);
                res++; 
            }
        }
        fin.push_back(com);
        rep(j,cnt) temp[j] = -1;
    }
    ll num = -1;
    for(ll f: fin){
        if(num == -1){
            num = f;
            continue;
        }
        num += f;
        res++;
        if(num>=10){
            num = 1 + (num%10);
            res++; 
        }
    }
    cout << res << endl;
}