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
    int p; cin >> p;

    string s; cin >> s;

    int mod10[n];
    rep(i,n){
        if(i == 0) mod10[i] = 1;
        else{
            mod10[i] = mod10[i-1] * (10 % p) % p;
        }
    }
    // rep(i,n) cout << mod10[i] << endl;

    int mod[n];
    rep(i,n){
        int si = s[n-i-1] - '0';
        mod[i] = si * mod10[i] % p;
        
    }

    int modsum[n+1];
    modsum[0] = 0;
    rep(i,n){
        if(i == 0) modsum[i+1] = mod[i];
        else{
            modsum[i+1] = (mod[i] + modsum[i]) % p;
        }
    }

    if(10%p == 0){
        ll res = 0;
        rep(r,n){
            if((s[r]-'0') % p == 0){
                res += r+1;
            }
        }
        cout << res << endl;
    }else{
        int cnt[p];
        rep(i,p) cnt[i] = 0;
        
        ll res = 0;
        rep(i,n+1){
            res += cnt[modsum[i]];
            cnt[modsum[i]]++;
        }

        cout << res << endl;
    }
}